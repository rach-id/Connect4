#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <QGraphicsPixmapItem>
#include <QDialog>

namespace Ui {
class GamePLay;
}

class GamePLay : public QDialog, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    explicit GamePLay(QWidget *parent = 0, int= 2, int = 7);
    ~GamePLay();
    int game;
private:
    Ui::GamePLay *ui;
    QGraphicsScene *scene;
    int dep;
    QWidget *dad;
};

#endif // GAMEPLAY_H
