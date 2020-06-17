#include "managerpage.h"
#include "ui_managerpage.h"

ManagerPage::ManagerPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManagerPage)
{
    ui->setupUi(this);
    this->usrm();

    QObject::connect(ui->usrmPushButton, &QPushButton::clicked, this, &ManagerPage::usrm);
    QObject::connect(ui->libmPushButton, &QPushButton::clicked, this, &ManagerPage::libm);
    QObject::connect(ui->brmPushButton, &QPushButton::clicked, this, &ManagerPage::brm);
}

ManagerPage::~ManagerPage()
{
    delete ui;
}

void ManagerPage::usrm(){
    ui->brmPage->hide();
    ui->libmPage->hide();
    ui->usrmPage->show();
}
void ManagerPage::libm(){
    ui->usrmPage->hide();
    ui->brmPage->hide();
    ui->libmPage->show();
}
void ManagerPage::brm(){
    ui->libmPage->hide();
    ui->usrmPage->hide();
    ui->brmPage->show();
}
