#include "addrdialog.h"
#include "ui_addrdialog.h"
#include "Library.h"
#include "Functions.h"

#include <QMessageBox>

extern Library lib;
AddRDialog::AddRDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRDialog),
    regx("[a-zA-Z0-9]+$"),
    validator(new QRegExpValidator(regx, this))
{
    ui->setupUi(this);
    this->setWindowTitle(tr("添加用户"));

    ui->IDLineEdit->setValidator(validator);
    ui->IDLineEdit->setAttribute(Qt::WA_InputMethodEnabled, false);

    QObject::connect(ui->confirmPushButton, &QPushButton::clicked, this, &AddRDialog::addReader);
    QObject::connect(ui->cancelPushButton, &QPushButton::clicked, this, &AddRDialog::close);
}

AddRDialog::~AddRDialog()
{
    delete ui;
}
void AddRDialog::clear(){
    ui->IDLineEdit->clear();
    ui->usrnameLineEdit->clear();

    ui->IDLineEdit->setFocus();
}
void AddRDialog::addReader(){
    QMessageBox msgbox(QMessageBox::Information, tr("提示"), tr(""));
    msgbox.setButtonText(QMessageBox::Ok, tr("确 定"));
    if(ui->IDLineEdit->text() == "" || ui->usrnameLineEdit->text() == ""){
        msgbox.setText(tr("请输入ID和用户名"));
        msgbox.exec();
        return;
    }
    std::string rid = ui->IDLineEdit->text().toStdString();
    std::string rname = ui->usrnameLineEdit->text().toStdString();
    std::string rpasswd = "000000";
    replace(rid," ","_");
    replace(rname," ","_");
    if(lib.op.ridExist(rid)){
        msgbox.setText(tr("ID已存在"));
        msgbox.exec();
        this->clear();
        return;
    }

    lib.mop.addReader(Reader(rid, rname, rpasswd));
    this->hide();
    msgbox.setText(tr("添加读者成功！\n初始密码：000000"));
    msgbox.exec();
    this->clear();
    this->accept();
}
