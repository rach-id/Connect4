#include "balldown.h"
#include <QTimer>


BallDown::BallDown(int i, int j) : correctY(j)
{
    // drawing the ball
    if(i == 0)
    {
        setPixmap(QPixmap(":/rec/rec/balll.png"));
        setPos(135,6.5);
    }
    else if (i == 1)
    {
        setPixmap(QPixmap(":/rec/rec/blackball.png"));
        setPos(135,6.5);
    }

    // connect
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(30);
}

void BallDown::move()
{
    //move Ball down
    if(y() < 1.5 + 6 * 65 - correctY * 65) setPos(x(),y()+75.5);
    if(y() >= 90) setPos(x(),y());

}
