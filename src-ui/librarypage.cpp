#include "librarypage.h"
#include <qdebug.h>
extern Library lib;
extern std::string loginID;

Librarypage::Librarypage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Librarypage)
{
    ui->setupUi(this);
    this->show_before();
    show_popularbooks();

    OpBtnDelegate* popular_dele = new OpBtnDelegate(OpBtnDelegate::Library,6,ui->PopularBooks);
    ui->PopularBooks->setItemDelegate(popular_dele);
    OpBtnDelegate* results_dele = new OpBtnDelegate(OpBtnDelegate::Library,6,ui->SearchResultsTableView);
    ui->SearchResultsTableView->setItemDelegate(results_dele);

    QObject::connect(ui->KeywordsEdit, &QLineEdit::returnPressed, this, &Librarypage::search);
    QObject::connect(ui->SearchButton, &QPushButton::clicked, this, &Librarypage::search);
    QObject::connect(ui->ReturnButton, &QPushButton::clicked, this, &Librarypage::show_before);
    QObject::connect(ui->allbooks, &QPushButton::clicked, this, &Librarypage::show_allbooks);
    QObject::connect(popular_dele, &OpBtnDelegate::detail, this, &Librarypage::popular_show_detail);
    QObject::connect(popular_dele, &OpBtnDelegate::borrow, this, &Librarypage::popular_borrow);
    QObject::connect(results_dele, &OpBtnDelegate::detail, this, &Librarypage::results_show_detail);
    QObject::connect(results_dele, &OpBtnDelegate::borrow, this, &Librarypage::results_borrow);

}

Librarypage::~Librarypage(){
    delete ui;
}


void Librarypage::show_before(){
    ui->Before->show();
    ui->After->hide();
    ui->KeywordsEdit->clear();
}

void Librarypage::show_after(){
    ui->Before->hide();
    ui->After->show();
}

void Librarypage::search(){
    if(ui->KeywordsEdit->text() == ""){ QMessageBox::warning(this, tr("错误！"), tr("你没有键入任何字符！")); }
    else{
        show_after();
        ui->SearchResultsTableView->setModel(lib.op.QschBook(ui->KeywordsEdit->text().toStdString()));
        format_results();
    }
}

void Librarypage::show_popularbooks(){
    lib.op.sortByBorrow();
    ui->PopularBooks->setModel(lib.op.QshowBook(10));
    format_popular();
}

void Librarypage::popular_show_detail(const QModelIndex index){
    show_detail(index,ui->PopularBooks);
}

void Librarypage::popular_borrow(const QModelIndex index){
    borrow(index,ui->PopularBooks);
}

void Librarypage::show_allbooks(){
    show_after();
    ui->SearchResultsTableView->setModel(lib.op.QshowBook());
    format_results();
}

void Librarypage::results_show_detail(const QModelIndex index){
    show_detail(index,ui->SearchResultsTableView);
}

void Librarypage::results_borrow(const QModelIndex index){
    borrow(index,ui->SearchResultsTableView);
}

void Librarypage::show_detail(const QModelIndex index, const QTableView* view){
    BookDetail* detail_dailog = new BookDetail(this,
                                               view->model()->index(index.row(), 0).data().toString(),
                                               view->model()->index(index.row(), 1).data().toString(),
                                               view->model()->index(index.row(), 2).data().toString(),
                                               view->model()->index(index.row(), 3).data().toString());
    detail_dailog->exec();
}

void Librarypage::borrow(const QModelIndex index, const QTableView* view){
    if(loginID=="-1"){QMessageBox::critical(this, tr("错误"), tr("若需要借阅此书籍，请先登入系统！"));return;}
    if(loginID=="Admin"){QMessageBox::critical(this, tr("错误"), tr("管理员不具备借书能力！"));return;}
    else{
        if(QMessageBox::Yes == QMessageBox::question(this,tr("确认借阅请求"),tr("确认发出借阅请求么？"),QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes)){
        lib.rop.reqBorrow(view->model()->index(index.row(), 0).data().toString().toStdString());
        QMessageBox::about(this, tr("借阅申请"), tr("借阅申请已发出!\n正在等待管理员的审核。"));

        }
    }
}

void Librarypage::format_popular(){
    ui->PopularBooks->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->PopularBooks->setSelectionMode(QAbstractItemView::NoSelection);
    ui->PopularBooks->setShowGrid(false);
    ui->PopularBooks->verticalHeader()->hide();
    ui->PopularBooks->setAlternatingRowColors(true);
    ui->PopularBooks->hideColumn(0);
    ui->PopularBooks->hideColumn(3);
    ui->PopularBooks->hideColumn(5);
    ui->PopularBooks->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->PopularBooks->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    ui->PopularBooks->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    ui->PopularBooks->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);
    ui->PopularBooks->horizontalHeader()->setMinimumSectionSize(60);
}

void Librarypage::format_results(){
    ui->SearchResultsTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->SearchResultsTableView->setSelectionMode(QAbstractItemView::NoSelection);
    ui->SearchResultsTableView->setShowGrid(false);
    ui->SearchResultsTableView->verticalHeader()->hide();
    ui->SearchResultsTableView->setAlternatingRowColors(true);
    ui->SearchResultsTableView->hideColumn(0);
    ui->SearchResultsTableView->hideColumn(5);
    ui->SearchResultsTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->PopularBooks->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    ui->PopularBooks->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    ui->PopularBooks->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    ui->PopularBooks->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);
    ui->PopularBooks->horizontalHeader()->setMinimumSectionSize(60);
}
