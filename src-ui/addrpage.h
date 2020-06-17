#ifndef ADDRPAGE_H
#define ADDRPAGE_H

#include <QWidget>

namespace Ui {
class AddRPage;
}

class AddRPage : public QWidget
{
    Q_OBJECT

public:
    explicit AddRPage(QWidget *parent = 0);
    ~AddRPage();

private:
    Ui::AddRPage *ui;
};

#endif // ADDRPAGE_H
