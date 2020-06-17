#include "libmpage.h"
#include "ui_libmpage.h"
#include "Library.h"
#include "addbdialog.h"
#include "addnbdialog.h"

#include <QMessageBox>
#include <QDebug>

extern Library lib;
extern std::string loginID;
LibmPage::LibmPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LibmPage)
{
    ui->setupUi(this);
    ui->libmTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->libmTableView->setSelectionMode(QAbstractItemView::NoSelection);
    ui->libmTableView->setShowGrid(false);
    ui->libmTableView->verticalHeader()->hide();

    ui->libmTableView->setAlternatingRowColors(true);

    BtnDelegate = new OpBtnDelegate(OpBtnDelegate::Book, 6, ui->libmTableView);
    ui->libmTableView->setItemDelegate(BtnDelegate);

    ui->searchPushButton->setStyleSheet("QPushButton{border-image: url(:/image/search1);}"
                                  "QPushButton:hover{border-image: url(:/image/search1);}"
                                  "QPushButton:pressed{border-image: url(:/image/search2);}");

    QObject::connect(ui->searchLineEdit, &QLineEdit::returnPressed, this, &LibmPage::searchBook);
    QObject::connect(ui->all_bookPushButton, &QPushButton::clicked, this, &LibmPage::showBook);
    QObject::connect(BtnDelegate, &OpBtnDelegate::add, this, &LibmPage::AddBook);
    QObject::connect(ui->addnbPushButton, &QPushButton::clicked, this, &LibmPage::AddnBook);
    QObject::connect(ui->searchPushButton, &QPushButton::clicked, this, &LibmPage::searchBook);
    QObject::connect(BtnDelegate, &OpBtnDelegate::del, this, &LibmPage::delBook);
}
void LibmPage::adjHeader(){
    ui->libmTableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->libmTableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    ui->libmTableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->libmTableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
    ui->libmTableView->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);
    ui->libmTableView->horizontalHeader()->setSectionResizeMode(5, QHeaderView::ResizeToContents);
    ui->libmTableView->horizontalHeader()->setSectionResizeMode(6, QHeaderView::Stretch);
    ui->libmTableView->horizontalHeader()->setMinimumSectionSize(80);
}
LibmPage::~LibmPage(){
    delete ui;
}
void LibmPage::showBook(){
    ui->libmTableView->setModel(lib.op.QshowBook());
    ui->libmTableView->setItemDelegateForColumn(6, BtnDelegate);
    this->adjHeader();
}
void LibmPage::AddBook(const QModelIndex &index){
    std::string bid_selected = ui->libmTableView->model()->index(index.row(), 0).data().toString().toStdString();
    AddBDialog addb(bid_selected);
    if(addb.exec() == QDialog::Accepted) this->showBook();
}
void LibmPage::AddnBook(){
    AddnBDialog anb;
    if(anb.exec() == QDialog::Accepted) this->showBook();
}
void LibmPage::searchBook(){
    if(ui->searchLineEdit->text() == ""){
        this->showBook();
        ui->searchLineEdit->clear();
        return;
    }
    if(ui->searchComboBox->currentIndex() == 0){
        ui->libmTableView->setModel(lib.op.QschBook(ui->searchLineEdit->text().toStdString()));
        ui->searchLineEdit->clear();
    }//混合搜索
    this->adjHeader();
    return;
}
void LibmPage::delBook(const QModelIndex &index){
    std::string bid_selected = ui->libmTableView->model()->index(index.row(), 0).data().toString().toStdString();
    if(!lib.mop.canDelb(bid_selected)){
        QMessageBox msgbox(QMessageBox::Information, tr("提示"), tr("该书不全在库中,无法删除"));
        msgbox.setButtonText(QMessageBox::Ok, tr("确 定"));
        msgbox.exec();
        return;
    }

    QStringList line = lib.op.QshowBook(bid_selected);
    QMessageBox msgbox(QMessageBox::Question, tr("提示"), QString("是否删除书籍\n《%1》").arg(line.value(1)));
    msgbox.setStandardButtons (QMessageBox::Ok|QMessageBox::Cancel);
    msgbox.setButtonText(QMessageBox::Ok, tr("确 定"));
    msgbox.setButtonText(QMessageBox::Cancel, tr("取 消"));
    if(msgbox.exec() == QMessageBox::Ok){
        lib.mop.delBook(bid_selected);
        this->showBook();
    }
}
