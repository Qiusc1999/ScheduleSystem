#ifndef WARNING_PSWDERRORFORM_H
#define WARNING_PSWDERRORFORM_H

#include <QWidget>

namespace Ui {
class Warning_PswdErrorForm;
}

class Warning_PswdErrorForm : public QWidget
{
    Q_OBJECT

public:
    explicit Warning_PswdErrorForm(QWidget *parent = nullptr);
    ~Warning_PswdErrorForm();

private slots:
    void on_pushButton_clicked();
    void receiveShow();

private:
    Ui::Warning_PswdErrorForm *ui;
};

#endif // WARNING_PSWDERRORFORM_H
