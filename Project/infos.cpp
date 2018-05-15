#include "infos.h"
#include "ui_infos.h"

Infos::Infos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Infos)
{
    ui->setupUi(this);
    setWindowTitle("Game Informations");
    show();
}

Infos::~Infos()
{
    delete ui;
}

void Infos::setLabel(QString turn)
{
    ui->label_2->setText(turn);
}

void Infos::setLabel1(int numbere)
{
    QString s = QString::number(numbere);
    ui->label_3->setText(s);
}

void Infos::setLabel2(QString algo)
{
    ui->label_4->setText(algo);
}

void Infos::setLabel3(QString algo)
{
    ui->label_5->setText(algo);
}
void Infos::setLabel4(int numbere)
{
    QString s = QString::number(numbere);
    ui->label_6->setText(s);
}


