#include "editinfodialog.h"
#include "ui_editinfodialog.h"
#include "Library.h"

#include <QMessageBox>

extern Library lib;
extern std::string loginID;
EditInfoDialog::EditInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditInfoDialog)
{
    ui->setupUi(this);
    QObject::connect(ui->confirmPushButton, &QPushButton::clicked, this, &EditInfoDialog::InfoEdit);
}

EditInfoDialog::~EditInfoDialog()
{
    delete ui;
}

void EditInfoDialog::InfoEdit(){
    QMessageBox msgbox(QMessageBox::Information, tr("提示"), tr(""));
    msgbox.setButtonText(QMessageBox::Ok, tr("确 定"));
    if(ui->pre_pswLineEdit->text() == ""){
        msgbox.setText(tr("请输入旧密码"));
        msgbox.exec();
        return;
    }
    if(ui->new_pswLineEdit->text() == ""){
        msgbox.setText(tr("请输入新密码"));
        msgbox.exec();
        return;
    }
    if(ui->psw_confirmLneEdit->text() == ""){
        msgbox.setText(tr("请再次输入密码"));
        msgbox.exec();
        return;
    }
    if(loginID == "Admin"){
        if(!lib.mop.mpasswdRight(ui->pre_pswLineEdit->text().toStdString())){
            msgbox.setText(tr("旧密码错误"));
            msgbox.exec();
            ui->pre_pswLineEdit->clear();
            return;
        }
    }
    else{
        if(!lib.rop.rpasswdRight(ui->pre_pswLineEdit->text().toStdString())){
            msgbox.setText(tr("旧密码错误"));
            msgbox.exec();
            ui->pre_pswLineEdit->clear();
            return;
        }
    }
    if(ui->new_pswLineEdit->text() != ui->psw_confirmLneEdit->text()){
        msgbox.setText(tr("两次输入密码不一致"));
        msgbox.exec();
        ui->psw_confirmLneEdit->clear();
        ui->new_pswLineEdit->clear();
        return;
    }
    loginID == "Admin" ? lib.mop.changeMpasswd(ui->new_pswLineEdit->text().toStdString()) : lib.rop.changeRpasswd(ui->new_pswLineEdit->text().toStdString());
    msgbox.setText(tr("修改密码成功"));
    msgbox.exec();
    this->accept();
}
