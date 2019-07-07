#ifndef INFO_REGISTERSUCESSFORM_H
#define INFO_REGISTERSUCESSFORM_H

#include <QWidget>

namespace Ui {
class Info_RegisterSucessForm;
}

class Info_RegisterSucessForm : public QWidget
{
    Q_OBJECT

public:
    explicit Info_RegisterSucessForm(QWidget *parent = nullptr);
    ~Info_RegisterSucessForm();

private slots:
    void on_pushButton_clicked();
    void receiveShow();

signals:
    void showMain();
    void showLogin();

private:
    Ui::Info_RegisterSucessForm *ui;
};

#endif // INFO_REGISTERSUCESSFORM_H
