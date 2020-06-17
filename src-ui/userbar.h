#ifndef USERBAR_H
#define USERBAR_H

#include <QWidget>
#include <QValidator>

namespace Ui {
class Userbar;
}

class Userbar : public QWidget
{
    Q_OBJECT

public:
    explicit Userbar(QWidget *parent = 0);
    ~Userbar();
    void clearInp();
    void clearLab();
    void login();
    void reg();
    void logout();
    void infoEdit();

signals:
    void mlogin();
    void mlogout();
    void rlogin();
    void rlogout();

private:
    Ui::Userbar *ui;
    QRegExp regx;
    QValidator *validator;
};

#endif // USERBAR_H
