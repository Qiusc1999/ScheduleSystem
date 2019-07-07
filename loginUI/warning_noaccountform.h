#ifndef WARNING_NOACCOUNTFORM_H
#define WARNING_NOACCOUNTFORM_H

#include <QWidget>

namespace Ui {
class Warning_noAccountForm;
}

class Warning_noAccountForm : public QWidget
{
    Q_OBJECT

public:
    explicit Warning_noAccountForm(QWidget *parent = nullptr);
    ~Warning_noAccountForm();
private slots:
    void receiveShow();
    void on_pushButton_clicked();

private:
    Ui::Warning_noAccountForm *ui;
};

#endif // WARNING_NOACCOUNTFORM_H
