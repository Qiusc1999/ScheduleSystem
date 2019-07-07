#ifndef WARNING_FILENOTFOUNDFORM_H
#define WARNING_FILENOTFOUNDFORM_H

#include <QWidget>

namespace Ui {
class warning_accountNullform;
}

class warning_accountNullform : public QWidget
{
    Q_OBJECT

public:
    explicit warning_accountNullform(QWidget *parent = nullptr);
    ~warning_accountNullform();

private slots:
    void receiveShow();
    void on_pushButton_clicked();

private:
    Ui::warning_accountNullform *ui;
};

#endif // WARNING_FILENOTFOUNDFORM_H
