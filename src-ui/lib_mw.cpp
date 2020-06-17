#include "lib_mw.h"
#include "ui_lib_mw.h"
#include <iostream>
#include <QApplication>

Lib_MW::Lib_MW(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Lib_MW)
{
    ui->setupUi(this);
    ui->statusBar->hide();
    ui->menuBar->hide();
    ui->mainToolBar->hide();

    ui->tabWidget->setTabEnabled(1, false);
    ui->tabWidget->setTabEnabled(2, false);

    QObject::connect(ui->userbar, &Userbar::mlogin, this, &Lib_MW::mlogin);
    QObject::connect(ui->userbar, &Userbar::mlogout, this, &Lib_MW::mlogout);
    QObject::connect(ui->userbar, &Userbar::rlogin, this, &Lib_MW::rlogin);
    QObject::connect(ui->userbar, &Userbar::rlogout, this, &Lib_MW::rlogout);

    this->setWindowTitle(tr("图书管理系统"));
}

Lib_MW::~Lib_MW()
{
    delete ui;
}

void Lib_MW::mlogin(){
    ui->tabWidget->setTabEnabled(2, true);
}
void Lib_MW::mlogout(){
    ui->tabWidget->setTabEnabled(2, false);
}
void Lib_MW::rlogin(){
    ui->tabWidget->setTabEnabled(1, true);
}
void Lib_MW::rlogout(){
    ui->tabWidget->setTabEnabled(1, false);
}
