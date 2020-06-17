#ifndef ADDNBDIALOG_H
#define ADDNBDIALOG_H

#include <QDialog>

namespace Ui {
class AddnBDialog;
}

class AddnBDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddnBDialog(QWidget *parent = 0);
    ~AddnBDialog();
    void addnBook();
    void clear();

private:
    Ui::AddnBDialog *ui;
};

#endif // ADDNBDIALOG_H
