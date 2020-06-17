#ifndef ADDBDIALOG_H
#define ADDBDIALOG_H

#include <QDialog>

namespace Ui {
class AddBDialog;
}

class AddBDialog : public QDialog
{
    Q_OBJECT
    std::string bid;
public:
    explicit AddBDialog(std::string _bid,QWidget *parent = 0);
    ~AddBDialog();
    void AddBook();

private:
    Ui::AddBDialog *ui;
};

#endif // ADDBDIALOG_H
