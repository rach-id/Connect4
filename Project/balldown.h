#ifndef BALLDOWN_H
#define BALLDOWN_H


#include <QObject>
#include <QGraphicsPixmapItem>

class BallDown : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    BallDown(int i= 0 , int = 0);
public slots:
    void move();
private:
    int correctY;
};






#endif // BALLDOWN_H
