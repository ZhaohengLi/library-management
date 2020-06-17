#include "addrpage.h"
#include "ui_addrpage.h"

AddRPage::AddRPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddRPage)
{
    ui->setupUi(this);
}

AddRPage::~AddRPage()
{
    delete ui;
}
