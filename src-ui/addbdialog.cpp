#include "addbdialog.h"
#include "ui_addbdialog.h"
#include "Library.h"

#include <QMessageBox>
#include <QString>
#include <QDebug>

extern Library lib;
AddBDialog::AddBDialog(std::string _bid, QWidget *parent) :
    QDialog(parent),
    bid(_bid),
    ui(new Ui::AddBDialog)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("增加书籍数量"));

    this->ui->tipslabel->setText(QString("请输入添加《%1》的数量").arg(lib.op.QshowBook(bid).value(1)));

    QObject::connect(ui->confirmPushButton, &QPushButton::clicked, this, &AddBDialog::AddBook);
    QObject::connect(ui->cancelPushButton, &QPushButton::clicked, this, &AddBDialog::close);
}

AddBDialog::~AddBDialog()
{
    delete ui;
}
void AddBDialog::AddBook(){
    lib.mop.addBook(bid, ui->addbSpinBox->value());
    this->hide();
    QMessageBox msgbox(QMessageBox::Information, tr("提示"),
                       QString("书籍添加成功\n\n已添加%1本《%2》").arg(ui->addbSpinBox->value()).arg(lib.op.QshowBook(bid).value(1)));
    msgbox.exec();
    this->accept();
}
