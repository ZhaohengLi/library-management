#ifndef LIBMPAGE_H
#define LIBMPAGE_H

#include "opbtndelegate.h"

#include <QWidget>

namespace Ui {
class LibmPage;
}

class LibmPage : public QWidget
{
    Q_OBJECT

public:
    explicit LibmPage(QWidget *parent = 0);
    ~LibmPage();
    void adjHeader();
    void showBook();
    void AddBook(const QModelIndex &index);
    void AddnBook();
    void searchBook();
    void delBook(const QModelIndex &index);

private:
    Ui::LibmPage *ui;
    OpBtnDelegate *BtnDelegate;
};

#endif // LIBMPAGE_H
