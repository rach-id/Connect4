#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "gameplay.h"
#include "secondmenu.h"
namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

private:
    Ui::Menu *ui;
    GamePLay *board;
    secondMenu* secondmenu;
};

#endif // MENU_H
