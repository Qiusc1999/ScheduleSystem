#ifndef THEMEFORM_H
#define THEMEFORM_H

#include <QWidget>

namespace Ui {
class themeForm;
}

class themeForm : public QWidget
{
    Q_OBJECT

public:
    explicit themeForm(QWidget *parent = nullptr);
    ~themeForm();

private slots:
    void on_pushButton_1_clicked();
    void receiveShow();
private:
    Ui::themeForm *ui;
};

#endif // THEMEFORM_H
