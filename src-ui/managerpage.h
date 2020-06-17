#ifndef MANAGERPAGE_H
#define MANAGERPAGE_H

#include <QWidget>

namespace Ui {
class ManagerPage;
}

class ManagerPage : public QWidget
{
    Q_OBJECT

public:
    explicit ManagerPage(QWidget *parent = 0);
    ~ManagerPage();
    void usrm();
    void libm();
    void brm();

private:
    Ui::ManagerPage *ui;
};

#endif // MANAGERPAGE_H
