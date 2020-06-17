#ifndef USRMPAGE_H
#define USRMPAGE_H

#include "opbtndelegate.h"
#include "qtablemodel.h"

#include <QWidget>

namespace Ui {
class UsrmPage;
}

class UsrmPage : public QWidget
{
    Q_OBJECT

public:
    explicit UsrmPage(QWidget *parent = 0);
    ~UsrmPage();
    void showReader(); //调用Library.h中op.showReader()
    void searchReader();
    void adjHeader();
    void addReader();
    void delReader(const QModelIndex &index);
    void editReader(const QModelIndex &index);

private:
    Ui::UsrmPage *ui;
    OpBtnDelegate *BtnDelegate;
};

#endif // USRMPAGE_H
