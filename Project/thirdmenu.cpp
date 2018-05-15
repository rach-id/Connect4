#include "thirdmenu.h"
#include "ui_thirdmenu.h"

ThirdMenu::ThirdMenu(QWidget *parent) : dad(parent),
    QDialog(parent),
    ui(new Ui::ThirdMenu)
{
    ui->setupUi(this);
}

ThirdMenu::~ThirdMenu()
{
    delete ui;
}

void ThirdMenu::on_pushButton_4_clicked()
{

    hide();
    board = new GamePLay(this, 2,3);
}

void ThirdMenu::on_pushButton_3_clicked()
{
    hide();
    board = new GamePLay(this, 2,6);
}

void ThirdMenu::on_pushButton_2_clicked()
{
    hide();
    board = new GamePLay(this, 2,7);
}

void ThirdMenu::on_pushButton_clicked()
{
    hide();
}
