#ifndef LOGINSUCCESSFORM_H
#define LOGINSUCCESSFORM_H

#include <QWidget>

namespace Ui {
class LoginSuccessForm;
}

class LoginSuccessForm : public QWidget
{
    Q_OBJECT

public:
    explicit LoginSuccessForm(QWidget *parent = nullptr);
    ~LoginSuccessForm();

private slots:
    void on_pushButton_clicked();
    void receiveShow();

signals:
    void showMain();
private:
    Ui::LoginSuccessForm *ui;
};

#endif // LOGINSUCCESSFORM_H
