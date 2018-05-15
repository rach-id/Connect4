#include "menu.h"
#include "ui_menu.h"
#include "gameplay.h"

Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}


void Menu::on_pushButton_clicked()
{
    hide();
    secondmenu = new secondMenu(this);
    secondmenu->show();
}

void Menu::on_pushButton_4_clicked()
{
    hide();
    this->close();
}
void Menu::on_pushButton_3_clicked()
{
    hide();
    board = new GamePLay(this, 1);
}
