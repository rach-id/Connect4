#include "secondmenu.h"
#include "ui_secondmenu.h"

secondMenu::secondMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondMenu)
{
    ui->setupUi(this);
}

secondMenu::~secondMenu()
{
    delete ui;
}

void secondMenu::on_pushButton_clicked()
{
    hide();
    board = new GamePLay(this, 3,7);
}

void secondMenu::on_pushButton_2_clicked()
{
    hide();
    thirdMenu = new ThirdMenu(this);
    thirdMenu->show();
}

void secondMenu::on_pushButton_3_clicked()
{
    hide();
}
