#include "usrmpage.h"
#include "ui_usrmpage.h"
#include "addrdialog.h"
#include "Library.h"

#include <QMessageBox>
#include <QDebug>

extern Library lib;
extern std::string loginID;
UsrmPage::UsrmPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UsrmPage)
{
    ui->setupUi(this);
    ui->usrmTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->usrmTableView->setSelectionMode(QAbstractItemView::NoSelection);
    ui->usrmTableView->setShowGrid(false);
    ui->usrmTableView->verticalHeader()->hide();

    ui->usrmTableView->setAlternatingRowColors(true);

    BtnDelegate = new OpBtnDelegate(OpBtnDelegate::Reader, 3, ui->usrmTableView);
    ui->usrmTableView->setItemDelegate(BtnDelegate);

    ui->searchPushButton->setStyleSheet("QPushButton{border-image: url(:/image/search1);}"
                                  "QPushButton:hover{border-image: url(:/image/search1);}"
                                  "QPushButton:pressed{border-image: url(:/image/search2);}");

    QObject::connect(ui->searchLineEdit, &QLineEdit::returnPressed, this, &UsrmPage::searchReader);
    QObject::connect(ui->all_usrPushButton, &QPushButton::clicked, this, &UsrmPage::showReader);
    QObject::connect(ui->searchPushButton, &QPushButton::clicked, this, &UsrmPage::searchReader);
    QObject::connect(ui->addrPushButton, &QPushButton::clicked, this, &UsrmPage::addReader);
    QObject::connect(BtnDelegate, &OpBtnDelegate::del, this, &UsrmPage::delReader);
    QObject::connect(BtnDelegate, &OpBtnDelegate::edit, this, &UsrmPage::editReader);
}

UsrmPage::~UsrmPage()
{
    delete ui;
}

void UsrmPage::adjHeader(){
    ui->usrmTableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->usrmTableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->usrmTableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    ui->usrmTableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    ui->usrmTableView->horizontalHeader()->setMinimumSectionSize(110);
}

void UsrmPage::showReader(){
    ui->usrmTableView->setModel(lib.op.QshowReader());
    this->adjHeader();
}
void UsrmPage::searchReader(){
    if(ui->searchLineEdit->text() == ""){
        this->showReader();
        ui->searchLineEdit->clear();
        return;
    }

    if(ui->searchComboBox->currentIndex() == 0){
        ui->usrmTableView->setModel(lib.mop.Qschrid(ui->searchLineEdit->text().toStdString()));
        ui->searchLineEdit->clear();
    }
    if(ui->searchComboBox->currentIndex() == 1){
        ui->usrmTableView->setModel(lib.mop.Qschrname(ui->searchLineEdit->text().toStdString()));
        ui->searchLineEdit->clear();
    }
    if(ui->searchComboBox->currentIndex() == 2){
        ui->usrmTableView->setModel(lib.mop.QschReader(ui->searchLineEdit->text().toStdString()));
        ui->searchLineEdit->clear();
    }
    this->adjHeader();
}
void UsrmPage::addReader(){
    AddRDialog ar;
    if(ar.exec() == QDialog::Accepted) this->showReader();
}
void UsrmPage::delReader(const QModelIndex &index){
    std::string rid_selected = ui->usrmTableView->model()->index(index.row(), 0).data().toString().toStdString();
    if(rid_selected == loginID){
        QMessageBox msgbox(QMessageBox::Information, tr("提示"), tr("不能删除当前已登录的用户"));
        msgbox.setButtonText(QMessageBox::Ok, tr("确 定"));
        msgbox.exec();
        return;
    }
    if(!lib.mop.canDelr(rid_selected)){
        QMessageBox msgbox(QMessageBox::Information, tr("提示"), tr("该读者还未归还所有书籍,无法删除"));
        msgbox.setButtonText(QMessageBox::Ok, tr("确 定"));
        msgbox.exec();
        return;
    }
    QStringList line = lib.op.QshowReader(rid_selected);
    QMessageBox msgbox(QMessageBox::Question, tr("提示"),
                       QString("是否删除读者\n\n %1 %2").arg(line.value(0), line.value(1)));
    msgbox.setStandardButtons (QMessageBox::Ok|QMessageBox::Cancel);
    msgbox.setButtonText(QMessageBox::Ok, tr("确 定"));
    msgbox.setButtonText(QMessageBox::Cancel, tr("取 消"));
    if(msgbox.exec() == QMessageBox::Ok){
        lib.mop.delReader(rid_selected);
        this->showReader();
    }
}
void UsrmPage::editReader(const QModelIndex &index){
    //do something
}
