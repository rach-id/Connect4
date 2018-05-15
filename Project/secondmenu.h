#ifndef SECONDMENU_H
#define SECONDMENU_H

#include <QDialog>
#include "gameplay.h"
#include "thirdmenu.h"
#include "ui_menu.h"

namespace Ui {
class secondMenu;
}

class secondMenu : public QDialog
{
    Q_OBJECT

public:
    explicit secondMenu(QWidget *parent = 0);
    ~secondMenu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::secondMenu *ui;
    ThirdMenu* thirdMenu;
    GamePLay *board;
    Ui::Menu *menu;
};

#endif // SECONDMENU_H
