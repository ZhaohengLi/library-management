#ifndef BOOKDETAIL_H
#define BOOKDETAIL_H

#include <QDialog>

namespace Ui {
class BookDetail;
}

class BookDetail : public QDialog
{
    Q_OBJECT

public:
    explicit BookDetail(QWidget *parent = 0, QString _bID = "0", QString _bname = "0",  QString _bauthor = "0", QString _bpublication = "0");
    ~BookDetail();
    void borrow();
private:
    Ui::BookDetail *ui;
    QString bID;
    QString bname;
    QString bauthor;
    QString bpublication;
};

#endif // BOOKDETAIL_H
