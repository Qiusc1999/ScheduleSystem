#ifndef ABOUTFORM_H
#define ABOUTFORM_H

#include <QWidget>

namespace Ui {
class AboutForm;
}

class AboutForm : public QWidget
{
    Q_OBJECT

public:
    explicit AboutForm(QWidget *parent = nullptr);
    ~AboutForm();

private slots:
    void receiveShow();
    void on_pushButton_clicked();
private:
    Ui::AboutForm *ui;
};

#endif // ABOUTFORM_H
