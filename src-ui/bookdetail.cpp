#include "bookdetail.h"
#include "ui_bookdetail.h"
#include <QMessageBox>
#include "Library.h"

extern Library lib;
extern std::string loginID;

BookDetail::BookDetail(QWidget *parent, QString _bID, QString _bname,  QString _bauthor, QString _bpublication) :
    QDialog(parent),
    ui(new Ui::BookDetail),
    bID(_bID), bname(_bname),  bauthor(_bauthor), bpublication(_bpublication)
{
    ui->setupUi(this);
    ui->bID_show->setText(bID);
    ui->bname_show->setText(bname);
    ui->bauthor_show->setText(bauthor);
    ui->bpublication_show->setText(bpublication);
    this->setWindowTitle(tr("书籍详情"));

    QObject::connect(ui->return_button, &QPushButton::clicked, this, &BookDetail::close);
    QObject::connect(ui->borrow_button, &QPushButton::clicked, this, &BookDetail::borrow);
    ui->return_button->setDefault(true);
}

BookDetail::~BookDetail()
{
    delete ui;
}


void BookDetail::borrow(){
    if(loginID=="-1"){QMessageBox::critical(this, tr("错误"), tr("若需要借阅此书籍，请先登入系统！"));}
    else{
        if(QMessageBox::Yes == QMessageBox::question(this,tr("确认借阅请求"),tr("确认发出借阅请求么？"),QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes)){
        lib.rop.reqBorrow(ui->bID_show->text().toStdString());
        QMessageBox::warning(this, tr("借阅申请"), tr("借阅申请已发出!\n正在等待管理员的审核。"));
        }
    }
}
