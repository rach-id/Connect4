#ifndef BALL_H
#define BALL_H

#include <QGraphicsPixmapItem>
#include "board.h"
#include "ia.h"
#include "menu.h"
#include "QGraphicsView"
#include "infos.h"
class Ball: public QGraphicsPixmapItem {
public:
    Ball(QWidget *parent=0, int a=2, int c = 7, Infos* =0);
    void keyPressEvent(QKeyEvent *event);
    void pointsView(QGraphicsView *v){vi = v;}
protected:
    int index;
    int turns;
    int correctY;
    Board *board;
    IA minimax;
    int oldindex;
    int game;
    int dep;
    bool pass;
    QWidget *dad;
    Menu* menu;
    int moveCount;
    QGraphicsView *vi;
    Infos* inf;
};
#endif // BALL_H
