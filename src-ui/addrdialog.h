#ifndef ADDRDIALOG_H
#define ADDRDIALOG_H

#include <QDialog>
#include <QValidator>

namespace Ui {
class AddRDialog;
}

class AddRDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddRDialog(QWidget *parent = 0);
    ~AddRDialog();
    void clear();
    void addReader();

private:
    Ui::AddRDialog *ui;
    QRegExp regx;
    QValidator *validator;
};

#endif // ADDRDIALOG_H
