#ifndef IA_H
#define IA_H

#include "infos.h"
#include "board.h"
#include <vector>
#include "move.h"
#include <iostream>

using namespace std;


// The AI Player is 2
class IA
{
public:
    IA();
    Move bestCoup(Board& board, int depth,int&,int );
    int minimax(Board& board , int depth, int player, int x,int y, int&);
    int alphabeta(Board &board, int depth, int player, int x, int y,int alpha, int beta, int &nombree);
    int performMoveminimax(Board board, int turn, int dep, Infos *inf) {
        int depth = dep ;
        int nombree = 0;
        int Y = bestCoup(board,depth, nombree, 1).getY();
        inf->setLabel1(nombree);
        inf->setLabel2("Le nombre d'iterations pour minimax est : ");
        return Y;
    }

    int performMovealphabeta(Board board, int turn,int dep, Infos *inf) {
        int depth = dep ;
        de = dep;
        int nombree = 0;
        int Y = bestCoup(board,depth, nombree, 2).getY();
        inf->setLabel4(nombree);
        inf->setLabel3("Le nombre d'iterations pour alphabeta est : ");
        return Y;
    }
    int evaluation(Board& board, int player);
    bool alreadyExists(vector<Move> moves, Move move);

    /* ****Methode de maximum et minimum**** */
    int maximum(int a, int b  ) {return (a>b)? a : b;}
    int minimum(int a, int b  ) {return (a<b)? a : b;}

private:
    int movePossibility;
    int score;
    int evaluationCount;
    int de;

};

#endif // IA_H
