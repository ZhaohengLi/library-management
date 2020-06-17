#ifndef USERPAGE_H
#define USERPAGE_H

#include <QWidget>

#include "opbtndelegate.h"
#include "bookdetail.h"

namespace Ui {
class UserPage;
}

class UserPage : public QWidget
{
    Q_OBJECT

public:
    explicit UserPage(QWidget *parent = 0);
    ~UserPage();

    void showReadingnow();
    void showborrowWaitting();
    void showreturnWaitting();
    void showAllhistory();
    void showDetail(const QModelIndex index);
    void returnBook(const QModelIndex index);
    void cancelborrowRequest(const QModelIndex index);
    void cancelreturnRequest(const QModelIndex index);
    void format();
private:
    Ui::UserPage *ui;
    OpBtnDelegate *dele = nullptr;
};

#endif // USERPAGE_H
