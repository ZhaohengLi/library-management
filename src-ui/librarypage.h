#ifndef LIBRARYPAGE_H
#define LIBRARYPAGE_H

#include <QWidget>

#include "ui_librarypage.h"
#include "Library.h"
#include "qtablemodel.h"
#include "opbtndelegate.h"
#include <QMessageBox>
#include "bookdetail.h"

namespace Ui {
class Librarypage;
}

class Librarypage : public QWidget
{
    Q_OBJECT

public:
    explicit Librarypage(QWidget *parent = 0);
    ~Librarypage();

    void show_before();
    void show_after();
    void show_popularbooks();
    void search();
    void popular_show_detail(const QModelIndex index);
    void popular_borrow(const QModelIndex index);
    void results_show_detail(const QModelIndex index);
    void results_borrow(const QModelIndex index);
    void show_detail(const QModelIndex index, const QTableView* view);
    void borrow(const QModelIndex index, const QTableView* view);
    void format_results();
    void format_popular();
    void show_allbooks();


private:
    Ui::Librarypage *ui;
    OpBtnDelegate* popular_dele;
    OpBtnDelegate* results_dele;
};

#endif // LIBRARYPAGE_H
