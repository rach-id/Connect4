#ifndef INFOS_H
#define INFOS_H

#include <QDialog>

namespace Ui {
class Infos;
}

class Infos : public QDialog
{
    Q_OBJECT

public:
    explicit Infos(QWidget *parent = 0);
    ~Infos();
    void setLabel(QString ="");
    void setLabel1(int);
    void setLabel2(QString ="");
    void setLabel3(QString ="");
    void setLabel4(int number);
private:
    Ui::Infos *ui;
};

#endif // INFOS_H
