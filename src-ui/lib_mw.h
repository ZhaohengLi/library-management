#ifndef LIB_MW_H
#define LIB_MW_H

#include <QMainWindow>

namespace Ui {
class Lib_MW;
}

class Lib_MW : public QMainWindow
{
    Q_OBJECT

public:
    explicit Lib_MW(QWidget *parent = 0);
    ~Lib_MW();
    void mlogin();
    void mlogout();
    void rlogin();
    void rlogout();

private:
    Ui::Lib_MW *ui;
};

#endif // LIB_MW_H
