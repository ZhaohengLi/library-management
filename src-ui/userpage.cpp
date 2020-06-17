#include "userpage.h"
#include "ui_userpage.h"
#include "Library.h"
#include <QMessageBox>
#include <QDebug>

extern Library lib;
extern std::string loginID;

UserPage::UserPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserPage)
{
    ui->setupUi(this);
    showReadingnow();

    QObject::connect(ui->readingnow, &QPushButton::clicked, this, &UserPage::showReadingnow);
    QObject::connect(ui->allhistory, &QPushButton::clicked, this, &UserPage::showAllhistory);
    QObject::connect(ui->borrowwaitting, &QPushButton::clicked, this, &UserPage::showborrowWaitting);
    QObject::connect(ui->returnwaitting, &QPushButton::clicked, this, &UserPage::showreturnWaitting);

}

UserPage::~UserPage()
{
    delete ui;
}

void UserPage::showReadingnow(){
    ui->tableView->setModel(lib.rop.QshowBorrowHis());
    if(dele != nullptr) delete dele;
    dele = new OpBtnDelegate(OpBtnDelegate::ReaderReq,8,ui->tableView);
    ui->tableView->setItemDelegate(dele);
    format();
    ui->tableView->showColumn(8);
    QObject::connect(dele, &OpBtnDelegate::detail, this, &UserPage::showDetail);
    QObject::connect(dele, &OpBtnDelegate::ReturnReq, this, &UserPage::returnBook);
}

void UserPage::showborrowWaitting(){
    ui->tableView->setModel(lib.rop.QshowBorrowReq());
    if(dele != nullptr) delete dele;
    dele = new OpBtnDelegate(OpBtnDelegate::CancelReq,8,ui->tableView);
    ui->tableView->setItemDelegate(dele);
    format();
    ui->tableView->showColumn(8);
    QObject::connect(dele, &OpBtnDelegate::Cancel, this, &UserPage::cancelborrowRequest);
}

void UserPage::showreturnWaitting(){
    ui->tableView->setModel(lib.rop.QshowReturnReq());
    if(dele != nullptr) delete dele;
    dele = new OpBtnDelegate(OpBtnDelegate::CancelReq,8,ui->tableView);
    ui->tableView->setItemDelegate(dele);
    format();
    ui->tableView->showColumn(8);
    QObject::connect(dele, &OpBtnDelegate::Cancel, this, &UserPage::cancelreturnRequest);
}

void UserPage::showAllhistory(){
    ui->tableView->setModel(lib.rop.QshowReturnHis());
    format();
    ui->tableView->hideColumn(8);
}

void UserPage::showDetail(const QModelIndex index){
    QStringList book(lib.op.QshowBook(this->ui->tableView->model()->index(index.row(), 3).data().toString().toStdString()));
    BookDetail* detail_dailog = new BookDetail(this,
                                               this->ui->tableView->model()->index(index.row(), 3).data().toString(),
                                               this->ui->tableView->model()->index(index.row(), 4).data().toString(),
                                               book.at(2),book.at(3));
    detail_dailog->exec();
}

void UserPage::returnBook(const QModelIndex index){
    lib.rop.reqReturn(this->ui->tableView->model()->index(index.row(), 0).data().toString().toStdString());
    QMessageBox::about(this, tr("还书申请"), tr("还书申请已发出!\n正在等待管理员的审核。"));
}
void UserPage::cancelborrowRequest(const QModelIndex index){
    lib.rop.canBorrow(this->ui->tableView->model()->index(index.row(), 0).data().toString().toStdString());
    QMessageBox::about(this, tr("取消借书申请"), tr("已取消借书申请。"));
}
void UserPage::cancelreturnRequest(const QModelIndex index){
    lib.rop.canReturn(this->ui->tableView->model()->index(index.row(), 0).data().toString().toStdString());
    QMessageBox::about(this, tr("取消还书申请"), tr("已取消还书申请。"));
}

void UserPage::format(){
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableView->setShowGrid(false);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->hideColumn(1);
    ui->tableView->hideColumn(2);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(5, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(6, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(7, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(8, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setMinimumSectionSize(60);
}
