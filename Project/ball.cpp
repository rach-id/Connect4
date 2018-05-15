#include "ball.h"
#include <QDebug>
#include <QKeyEvent>
#include "balldown.h"
#include <QGraphicsScene>
#include <iostream>
#include <QTimer>
#include <QMessageBox>


Ball::Ball(QWidget *parent, int a,int c, Infos *info) : index(0), turns(0), correctY(5) , game(a), dep(c), dad(parent), moveCount(1), inf(info)
{
    // Creating the initial ball
    setPixmap(QPixmap(":/rec/rec/blackball.png"));
    setPos(135,6.5);


    // Creating the game board
    board = new Board;

    if(game == 1)
    {
        inf->setLabel("Player 1 Move");
        inf->setLabel2("Pas de Minimax");
        inf->setLabel3("Pas de AlphaBeta");
    }
    if(game == 2)
    {
        inf->setLabel("Player Move");
        inf->setLabel2("Pas de Minimax");
        inf->setLabel3("Le nombre de mouvements pour AlphaBeta est : ");
        inf->setLabel4(0);
    }
    if(game == 3)
    {
        inf->setLabel("Player Move");
        inf->setLabel2("Le nombre de mouvements pour minimax est : ");
        inf->setLabel3("Le nombre de mouvements pour AlphaBeta est : ");
        inf->setLabel1(0);
        inf->setLabel4(0);
    }
}

void Ball::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)
    {
        menu = new Menu(0);
        menu->show();
        vi->hide();
        inf->hide();
    }
    if(event->key() == Qt::Key_Left && x() > 155)
    {
        index--;
        index = (index % 7 + 7) % 7 ;
        setPos(x()-78.5 , y());
    }
    else if(event->key() == Qt::Key_Left)
    {
        index--;
        index = (index % 7 + 7) % 7 ;
        setPos(x()+ 78.5 * 6 , y());
    }
    else if(event->key() == Qt::Key_Right && x() < 550)
    {
        index++;
        index = (index % 7 + 7) % 7 ;
        setPos(x()+78.5 , y());
    }
    else if(event->key() == Qt::Key_Right )
    {
        index++;
        index = (index % 7 + 7) % 7 ;
        setPos(x()- 78.5 * 6 , y());
    }
    else if(event->key() == Qt::Key_Space)
    {

        // Player vs Player
        oldindex = index;
        if(game == 1)
        {
            inf->setLabel("Player 1 Move");
            if(turns == 0)
            {
                inf->setLabel("Player 1 Move");
                // Adding the current move to the board
                correctY = board->makeMove(index, 1);

                if(correctY >= 0 )
                {
                    // Making the ball fall to its right place
                    BallDown *bully = new BallDown(1, 5- correctY);
                    bully->setPos(x(),y());
                    // adding it to the scene
                    scene()->addItem(bully);
                    if(board->checkVictory() == 1)
                    {
                        QMessageBox::critical(dad,"Player 1 wins","Click for another game" );
                        menu = new Menu(0);
                        menu->show();
                        vi->hide();
                        inf->hide();
                    }
                    pass = true;
                    inf->setLabel("Player 2 Move");
                }
            }

            else if (turns == 1 )
            {
                inf->setLabel("Player 2 Move");
                // Adding the current move to the board
                correctY = board->makeMove(index, 2);

                if(correctY >= 0)
                {

                    // Making the ball fall to its right place
                    BallDown *bully = new BallDown(0, 5-correctY);
                    bully->setPos(135 + index * 78.5 ,y());
                    // adding it to the scene
                    scene()->addItem(bully);
                    vi->update();
                    if(board->checkVictory() == 2)
                    {
                        QMessageBox::critical(dad,"Player 2 wins","Click for another game" );
                        menu = new Menu(0);
                        menu->show();
                        vi->hide();
                        inf->hide();
                    }
                    pass = true;
                    inf->setLabel("Player 1 Move");
                }
            }
            if (turns == 1 && pass)
            {
                this->setPixmap(QPixmap(":/rec/rec/blackball.png"));
                this->setPos(135  + index * 78.5 ,y());
                turns = 0;
                pass =false;
            }
            else if (turns == 0 && pass)
            {
                this->setPixmap(QPixmap(":/rec/rec/balll.png"));
                this->setPos(135 + index * 78.5 ,y());
                turns = 1;
                pass = false;
            }
        }






        // Player vs AI
        else if(game == 2)
        {
            inf->setLabel("Computer Move");
            // Adding the current move to the board
            correctY = board->makeMove(index, 1);

            if(correctY >= 0 )
            {
                // Making the ball fall to its right place
                BallDown *bully = new BallDown(1, 5- correctY);
                bully->setPos(x(),y());
                // adding it to the scene
                scene()->addItem(bully);
                if(board->checkVictory() == 1)
                {
                    QMessageBox::critical(dad,"Player wins","Click for another game" );
                    menu = new Menu(0);
                    menu->show();
                    vi->hide();
                    inf->hide();
                }
            }
            if(moveCount == 1)
            {
                correctY = correctY-1;
                board->setCase(correctY, index);
                moveCount++;
            }
            else
            {
                index = IA().performMovealphabeta(*board, 2,dep , inf);
                correctY = board->makeMove(index, 2);
            }


            if(correctY >= 0)
            {
                // Making the ball fall to its right place
                BallDown *bully = new BallDown(0, 5-correctY);
                bully->setPos(135 + index * 78.5 ,y());
                // adding it to the scene
                scene()->addItem(bully);
                if(board->checkVictory() == 2)
                {
                    QMessageBox::critical(dad,"Computer wins","Click for another game" );
                    menu = new Menu(0);
                    menu->show();
                    vi->hide();
                    inf->hide();
                }
            }
            index = oldindex;
        }



        // Simulation phase
        else if(game == 3)
        {
            inf->setLabel("Computer Move");
            // Adding the current move to the board
            correctY = board->makeMove(index, 1);

            if(correctY >= 0 )
            {
                // Making the ball fall to its right place
                BallDown *bully = new BallDown(1, 5- correctY);
                bully->setPos(x(),y());
                // adding it to the scene
                scene()->addItem(bully);
                if(board->checkVictory() == 1)
                {
                    QMessageBox::critical(dad,"Player wins","Click for another game" );
                    menu = new Menu(0);
                    menu->show();
                    vi->hide();
                    inf->hide();
                }
            }
            inf->setLabel("Computer Move");
            if(moveCount == 1)
            {
                correctY = correctY-1;
                board->setCase(correctY, index);
                moveCount++;
            }
            else
            {
                index = IA().performMoveminimax(*board, 2,dep,inf);
                index = IA().performMovealphabeta(*board, 2,dep,inf);
                correctY = board->makeMove(index, 2);
            }

            if(correctY >= 0)
            {
                // Making the ball fall to its right place
                BallDown *bully = new BallDown(0, 5-correctY);
                bully->setPos(135 + index * 78.5 ,y());
                // adding it to the scene
                scene()->addItem(bully);
                if(board->checkVictory() == 2)
                {
                    QMessageBox::critical(dad,"Computer wins","Click for another game" );
                    menu = new Menu(0);
                    menu->show();
                    vi->hide();
                    inf->hide();
                }

            }
            index = oldindex;
            inf->setLabel("Player Move");
        }

     }

}
