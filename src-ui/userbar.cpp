#include "userbar.h"
#include "ui_userbar.h"
#include "Library.h"
#include "editinfodialog.h"
#include <QMessageBox>
#include <QDebug>

extern Library lib;
extern std::string loginID;
Userbar::Userbar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Userbar),
    regx("[a-zA-Z0-9]+$"),
    validator(new QRegExpValidator(regx, this))
{
    ui->setupUi(this);
    this->logout();

    ui->usrIDLineEdit->setValidator(validator);
    ui->pswLineEdit->setValidator(validator);
    ui->usrIDLineEdit->setAttribute(Qt::WA_InputMethodEnabled, false);
    ui->pswLineEdit->setAttribute(Qt::WA_InputMethodEnabled, false);

    QObject::connect(ui->loginPushButton, &QPushButton::clicked, this, &Userbar::login);
    QObject::connect(ui->regPushButton, &QPushButton::clicked, this, &Userbar::reg);
    QObject::connect(ui->logoutPushButton, &QPushButton::clicked, this, &Userbar::logout);
    QObject::connect(ui->info_editPushButton, &QPushButton::clicked, this, &Userbar::infoEdit);
}
Userbar::~Userbar()
{
    delete ui;
}
void Userbar::clearInp(){
    ui->usrIDLineEdit->clear();
    ui->pswLineEdit->clear();
    ui->usrIDLineEdit->setFocus();
}
void Userbar::clearLab(){
    ui->staLabel->clear();
    ui->IDLabel->clear();
    ui->usrnameLabel->clear();
}
void Userbar::login() {
    lib.rop.logout();

    QMessageBox msgbox(QMessageBox::Information, tr("提示"), tr(""));
    msgbox.setButtonText(QMessageBox::Ok, tr("确 定"));
    if(ui->usrIDLineEdit->text() == "" || ui->pswLineEdit->text() == ""){
        msgbox.setText(tr("请输入ID和密码"));
        msgbox.exec();
        return;
    }
    if(ui->adminRadioButton->isChecked()){
        if(ui->usrIDLineEdit->text() != "Admin" || !lib.mop.mpasswdRight(ui->pswLineEdit->text().toStdString())) {
            msgbox.setText(tr("管理员ID或密码错误"));
            msgbox.exec();
            this->clearInp();
            return;
        }
        msgbox.setText(tr("管理员登录成功！"));
        msgbox.exec();

        loginID = "Admin";

        emit mlogin();

        ui->loginfo->hide();
        ui->staLabel->setText(tr("权限：管理员"));
        ui->IDLabel->setText(tr("ID：Admin"));
        ui->usrnameLabel->setText(tr("用户名：Admin"));
        ui->usrinfo->show();
        return;
    }
    if(ui->readerRadioButton->isChecked()){
        if(!lib.op.ridExist(ui->usrIDLineEdit->text().toStdString())){
            msgbox.setText(tr("ID不存在"));
            msgbox.exec();
            this->clearInp();
            return;
        }
        lib.rop.setReader(ui->usrIDLineEdit->text().toStdString());
        if(!lib.rop.rpasswdRight(ui->pswLineEdit->text().toStdString())){
            msgbox.setText(tr("ID或密码错误"));
            msgbox.exec();
            this->clearInp();
            return;
        }
        lib.rop.setReader(ui->usrIDLineEdit->text().toStdString());
        msgbox.setText(tr("登录成功！"));
        msgbox.exec();

        loginID = lib.rop.getRid();

        emit rlogin();

        ui->loginfo->hide();
        ui->staLabel->setText(tr("权限：读者"));
        ui->IDLabel->setText(QString("ID：%1").arg(QString::fromStdString(lib.rop.getRid())));
        ui->usrnameLabel->setText(QString("用户名：%1").arg(QString::fromStdString(lib.rop.getRname())));
        ui->usrinfo->show();
        return;
    }
}
void Userbar::reg(){
    QMessageBox msgbox(QMessageBox::Information, tr("提示"), tr("请与管理员联系！"));
    msgbox.setButtonText(QMessageBox::Ok, tr("确 定"));
    msgbox.exec();
}
void Userbar::logout(){
    if(loginID == "Admin") emit mlogout();
    else{
        emit rlogout();
        lib.rop.logout();
    }
    loginID = "-1";
    this->clearLab();
    ui->usrinfo->hide();
    this->clearInp();
    ui->loginfo->show();
}
void Userbar::infoEdit(){
    EditInfoDialog ei;
    ei.exec();
}
