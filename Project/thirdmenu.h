#ifndef THIRDMENU_H
#define THIRDMENU_H

#include <QDialog>
#include "gameplay.h"

namespace Ui {
class ThirdMenu;
}

class ThirdMenu : public QDialog
{
    Q_OBJECT

public:
    explicit ThirdMenu(QWidget *parent = 0);
    ~ThirdMenu();

private slots:
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

private:
    Ui::ThirdMenu *ui;
    GamePLay *board;
    QWidget* dad;
};

#endif // THIRDMENU_H
