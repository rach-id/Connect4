#include "gameplay.h"
#include "ui_gameplay.h"
#include "menu.h"
#include <QApplication>
#include <QGraphicsScene>
#include "ball.h"
#include <QGraphicsView>
#include <QDebug>
#include <QBrush>
#include <QImage>
#include <iostream>
#include "infos.h"

int width = 800;
int height = 566;

GamePLay::GamePLay(QWidget *parent,int a, int c) : game(a), dep(c),dad(parent),
    QDialog(parent),
    ui(new Ui::GamePLay)
{
    ui->setupUi(this);

    // create a scene
    scene = new QGraphicsScene();
    // Creating the game dialog
    Infos* info = new Infos();
    info->focusPolicy();
    info->show();
    // Change the background
    scene->setBackgroundBrush(QBrush(QImage(":/rec/rec/gameBoard.png")));
    // create an item to put into the scene
    Ball *ballHuman = new Ball(dad , game, dep,info);
    scene->addItem(ballHuman);
    ballHuman->setFlag(QGraphicsItem::ItemIsFocusable);
    ballHuman->setFocus();

    // add a view
    QGraphicsView *view = new QGraphicsView(scene); //we need to it what scene to visualize
    ballHuman->pointsView(view);
    // The horizontal bar and the expanding of the window
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Fixing the view dimensions
    view->setFixedSize(800,566);
    scene->setSceneRect(0,0,800,566);

    // Showing function
    view->show();

}

GamePLay::~GamePLay()
{

    delete ui;
}

