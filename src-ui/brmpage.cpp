#include "brmpage.h"
#include "ui_brmpage.h"
#include "Library.h"

#include <QMessageBox>
#include <QDebug>

extern Library lib;
extern std::string loginID;
BRmPage::BRmPage(QWidget *parent) :
    QWidget(parent),
    htype(BRmPage::All),
    ui(new Ui::BRmPage){
    ui->setupUi(this);
    ui->brmTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->brmTableView->setSelectionMode(QAbstractItemView::NoSelection);
    ui->brmTableView->setShowGrid(false);
    ui->brmTableView->verticalHeader()->hide();

    ui->brmTableView->setAlternatingRowColors(true);
    ui->brmTableView->hideColumn(3);
    ui->brmTableView->hideColumn(5);
    ui->brmTableView->hideColumn(6);
    ui->brmTableView->hideColumn(7);

    delegate = new OpBtnDelegate(OpBtnDelegate::History, 8, ui->brmTableView);
    ui->brmTableView->setItemDelegate(delegate);

    ui->searchPushButton->setStyleSheet("QPushButton{border-image: url(:/image/search1);}"
                                  "QPushButton:hover{border-image: url(:/image/search1);}"
                                  "QPushButton:pressed{border-image: url(:/image/search2);}");

    QObject::connect(ui->searchLineEdit, &QLineEdit::returnPressed, this, &BRmPage::schHistory);
    QObject::connect(ui->all_BorrowReqPushButton, &QPushButton::clicked, this, &BRmPage::showBorrowReq);
    QObject::connect(ui->all_ReturnReqPushButton, &QPushButton::clicked, this, &BRmPage::showReturnReq);
    QObject::connect(ui->searchPushButton, &QPushButton::clicked, this, &BRmPage::schHistory);
    QObject::connect(delegate, &OpBtnDelegate::agr, this, &BRmPage::agrReq);
    QObject::connect(delegate, &OpBtnDelegate::ref, this, &BRmPage::refReq);
}
void BRmPage::adjHeader(){
    ui->brmTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->brmTableView->horizontalHeader()->setSectionResizeMode(8, QHeaderView::Stretch);
    ui->brmTableView->horizontalHeader()->setMinimumSectionSize(60);

}
BRmPage::~BRmPage(){
    delete ui;
}
void BRmPage::showBorrowReq(){
    htype = Borrow;
    ui->brmTableView->setModel(lib.mop.QshowBorrowReq());
    ui->brmTableView->showColumn(8);
    this->adjHeader();
}
void BRmPage::showReturnReq(){
    htype = Return;
    ui->brmTableView->setModel(lib.mop.QshowReturnReq());
    ui->brmTableView->showColumn(8);
    this->adjHeader();
}
void BRmPage::schHistory(){
    if(ui->searchComboBox->currentIndex() == 0){
        ui->brmTableView->setModel(lib.mop.QschHistory(ui->searchLineEdit->text().toStdString()));
        ui->brmTableView->hideColumn(8);
        this->adjHeader();
    }//混合搜索
    this->adjHeader();
}
void BRmPage::agrReq(const QModelIndex &index){
    if(htype == Borrow) this->agrBorrow(index);
    if(htype == Return) this->agrReturn(index);
}
void BRmPage::refReq(const QModelIndex &index){
    if(htype == Borrow) this->refBorrow(index);
    if(htype == Return) this->refReturn(index);
}
void BRmPage::agrBorrow(const QModelIndex &index){
    lib.mop.agrBorrow(ui->brmTableView->model()->index(index.row(), 0).data().toString().toStdString());
    QMessageBox msgbox(QMessageBox::Information, tr("提示"),
                       QString("已同意%1借阅\n《%2》").arg(
                       ui->brmTableView->model()->index(index.row(), 2).data().toString()).arg(
                       ui->brmTableView->model()->index(index.row(), 4).data().toString()));
    msgbox.setButtonText(QMessageBox::Ok, tr("确 定"));
    msgbox.exec();
    this->showBorrowReq();
}
void BRmPage::refBorrow(const QModelIndex &index){
    lib.mop.refBorrow(ui->brmTableView->model()->index(index.row(), 0).data().toString().toStdString());
    QMessageBox msgbox(QMessageBox::Information, tr("提示"),
                       QString("已拒绝%1借阅\n《%2》").arg(
                       ui->brmTableView->model()->index(index.row(), 2).data().toString()).arg(
                       ui->brmTableView->model()->index(index.row(), 4).data().toString()));
    msgbox.setButtonText(QMessageBox::Ok, tr("确 定"));
    msgbox.exec();
    this->showBorrowReq();
}
void BRmPage::agrReturn(const QModelIndex &index){
    qDebug() << ui->brmTableView->model()->index(index.row(), 0).data().toString();
    lib.mop.agrReturn(ui->brmTableView->model()->index(index.row(), 0).data().toString().toStdString());
    QMessageBox msgbox(QMessageBox::Information, tr("提示"),
                       QString("已同意%1归还\n《%2》").arg(
                       ui->brmTableView->model()->index(index.row(), 2).data().toString()).arg(
                       ui->brmTableView->model()->index(index.row(), 4).data().toString()));
    msgbox.setButtonText(QMessageBox::Ok, tr("确 定"));
    msgbox.exec();
    this->showReturnReq();
}
void BRmPage::refReturn(const QModelIndex &index){
    qDebug() << ui->brmTableView->model()->index(index.row(), 0).data().toString();
    lib.mop.refReturn(ui->brmTableView->model()->index(index.row(), 0).data().toString().toStdString());
    QMessageBox msgbox(QMessageBox::Information, tr("提示"),
                       QString("已拒绝%1归还\n《%2》").arg(
                       ui->brmTableView->model()->index(index.row(), 2).data().toString()).arg(
                       ui->brmTableView->model()->index(index.row(), 4).data().toString()));
    msgbox.setButtonText(QMessageBox::Ok, tr("确 定"));
    msgbox.exec();
    this->showReturnReq();
}
