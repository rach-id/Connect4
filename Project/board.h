#ifndef BOARD_H
#define BOARD_H

#include "move.h"
#include <vector>

class Board
{
public:

    /* ****Constructor & Destructors**** */
    Board();
    Board(Board&);
    ~Board();

    /* ****Methods**** */
    int checkVictory(); // Checks if a player won and returns its identity ( 1 : first player, 2 : second player, 0 : None won)
    int makeMove(int,int); // Makes the move we want
    void showYourself(); // Shows the grid
    void removeMove(int x , int y){board[x][y] = 0;} // Removes the move we want


    /* ****Getters and Setters**** */
    int getCase(int x , int y) {return board[x][y];}
    void setCase(int x,int y) {board[x][y] = 2;}

private:
    int** board;
    int winningCount; // Number of consecutive cases
};
#endif // BOARD_H
