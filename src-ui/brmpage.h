#ifndef BRMPAGE_H
#define BRMPAGE_H

#include "opbtndelegate.h"

#include <QWidget>

namespace Ui {
class BRmPage;
}

class BRmPage : public QWidget
{
    Q_OBJECT

public:
    explicit BRmPage(QWidget *parent = 0);
    ~BRmPage();
    void adjHeader();
    void showBorrowReq();
    void showReturnReq();
    void schHistory();
    void agrReq(const QModelIndex &index);
    void refReq(const QModelIndex &index);
    void agrBorrow(const QModelIndex &index);
    void refBorrow(const QModelIndex &index);
    void agrReturn(const QModelIndex &index);
    void refReturn(const QModelIndex &index);

private:
    enum Htype {All, Borrow, Return} htype;
    Ui::BRmPage *ui;
    OpBtnDelegate *delegate;
};

#endif // BRMPAGE_H
