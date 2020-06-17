#include "addnbdialog.h"
#include "ui_addnbdialog.h"
#include "Library.h"
#include "Book.h"
#include "Functions.h"
#include <QMessageBox>

extern Library lib;
AddnBDialog::AddnBDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddnBDialog)
{
    ui->setupUi(this);

    QObject::connect(ui->confirmPushButton, &QPushButton::clicked, this, &AddnBDialog::addnBook);
    QObject::connect(ui->cancelPushButton, &QPushButton::clicked, this, &AddnBDialog::close);
}

AddnBDialog::~AddnBDialog()
{
    delete ui;
}
void AddnBDialog::addnBook(){
    QMessageBox msgbox(QMessageBox::Information, tr("提示"), tr(""));
    msgbox.setButtonText(QMessageBox::Ok, tr("确 定"));
    if(ui->bidLineEdit->text() == "" || ui->bnameLineEdit->text() == "" ||
            ui->authorLineEdit->text() == "" || ui->pressLineEdit->text() == ""){
        msgbox.setText(tr("请补全信息"));
        msgbox.exec();
        return;
    }
    std::string bid = ui->bidLineEdit->text().toStdString();
    std::string bname = ui->bnameLineEdit->text().toStdString();
    std::string author = ui->authorLineEdit->text().toStdString();
    std::string press = ui->pressLineEdit->text().toStdString();
    replace(bid," ","_");
    replace(bname," ","_");
    replace(author," ","_");
    replace(press," ","_");
    if(lib.op.bidExist(bid)){
        msgbox.setText(tr("该ID已被其他书籍占用"));
        msgbox.exec();
        return;
    }
    lib.mop.addBook(Book(bid,bname,author,press,ui->numSpinBox->value()));
    this->hide();
    msgbox.setText(tr("添加书籍成功"));
    msgbox.exec();
    this->clear();
    this->accept();
}
void AddnBDialog::clear(){
    ui->bidLineEdit->clear();
    ui->bnameLineEdit->clear();
    ui->authorLineEdit->clear();
    ui->pressLineEdit->clear();
    ui->numSpinBox->setValue(1);

    ui->bidLineEdit->setFocus();
}
