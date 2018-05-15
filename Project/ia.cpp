#include "ia.h"
#include <iostream>

using namespace std;



IA::IA()
{

}




Move IA::bestCoup(Board &board, int depth, int& nombree, int algo)
{
    int bestValue = -10000000, coupValue=0;
    int index = 0;
    int alpha = -100000;
    int beta = 100000;
    Move bestMove(-1,-1,0);
    for(int j = 0; j < 7 ; j++)
    {
        index = board.makeMove(j,2);
        if(index != 0)
        {
            bestMove.setX(index);
            bestMove.setY(j);
            bestMove.setScore(coupValue);
            break;
        }
    }
    for(int j = 0 ; j < 7 ; j++)
    {
        index = board.makeMove(j,2);
        if(index != -1)
        {
            if(algo == 1) coupValue = minimax(board, depth-1 , 1, index, j,nombree);
            else coupValue = alphabeta(board, depth-1 , 1, index, j,alpha,beta,nombree);

            board.removeMove(index,j);
            if(coupValue > bestValue)
            {
                bestMove.setX(index);
                bestMove.setY(j);
                bestMove.setScore(coupValue);
                bestValue = coupValue;
            }
        }
    }

    return bestMove;
}









int IA::alphabeta(Board &board, int depth, int player, int x, int y,int alpha, int beta, int &nombree)
{

    int bestValue = 0;
    if (board.checkVictory() == 1) return -1000000;
    else if (board.checkVictory() == 2) return 1000000 ;
    if(depth == 0 )
    {
        if(player == 1 ) return - evaluation(board, 1);
        else return evaluation(board, 2);
    }

    int index = -1;
    if(player == 2)
    {
        bestValue = -10000000;
        for(int j =0 ; j <7 ; j++)
        {
            index = board.makeMove(j,player);
            if(index != -1)
            {
                nombree++;
                bestValue = maximum(bestValue, minimax(board,depth-1, 1 ,index,j,nombree));
                alpha = maximum(alpha, bestValue);
                board.removeMove(index,j);
                if(alpha > beta) break;
            }
        }
    }

    else
    {
        bestValue = +10000000;
        for(int j =0 ; j <7 ; j++)
        {
            index = board.makeMove(j,player);
            if(index != -1)
            {
                nombree++;
                bestValue = minimum(bestValue, minimax(board,depth-1,2,index,j,nombree));
                beta = minimum(beta, bestValue);
                board.removeMove(index,j);
                if(alpha > beta ) break;
            }
        }
    }
    return bestValue;
}










int IA::minimax(Board &board, int depth, int player, int x, int y, int &nombree)
{
    int bestValue = 0;
    if (board.checkVictory() == 1) return -1000000;
    else if (board.checkVictory() == 2) return 1000000 ;
    if(depth == 0 )
    {
        if(player == 1 ) return - evaluation(board, 1);
        else return evaluation(board, 2);
    }

    int index = -1;
    if(player == 2)
    {
        bestValue = -10000000;
        for(int j =0 ; j <7 ; j++)
        {
            index = board.makeMove(j,player);
            if(index != -1)
            {
                nombree++;
                bestValue = maximum(bestValue, minimax(board,depth-1, 1 ,index,j,nombree));
                board.removeMove(index,j);
            }
        }
    }

    else
    {
        bestValue = +10000000;
        for(int j =0 ; j <7 ; j++)
        {
            index = board.makeMove(j,player);
            if(index != -1)
            {
                nombree++;
                bestValue = minimum(bestValue, minimax(board,depth-1,2,index,j,nombree));
                board.removeMove(index,j);
            }
        }
    }
    return bestValue;
}
int IA::evaluation(Board &board, int player)
{
    vector <Move> alreadyEvaluated;
    int score = 0;
    for(int x = 0; x < 6 ;x++)
    {
        for(int y = 0 ; y < 7 ; y++)
        {
            if(not alreadyExists(alreadyEvaluated, Move(x,y)))
            {

                    evaluationCount = 1;
                    /* ****Vertical Up verification**** */
                    for (int i =1; i < 4 ; i++)
                    {
                        if(x + i < 6)
                        {
                            if(board.getCase(x,y) == player && board.getCase(x,y) == board.getCase(x+i,y))
                            {
                                alreadyEvaluated.push_back(Move(x+i,y));
                                evaluationCount++;
                            }
                            else
                            {
                                break;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }

                    /* ****Vertical down verification**** */
                    for (int i =1; i < 4 ; i++)
                    {
                        if(x - i >= 0)
                        {
                            if(board.getCase(x,y) == player && board.getCase(x,y) == board.getCase(x-i,y))
                            {
                                alreadyEvaluated.push_back(Move(x-i,y));
                                evaluationCount++;
                            }
                            else
                            {
                                break;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }


                    if(player == 2)
                    {
                        if(evaluationCount == 1)  score = score + 5;
                        else if(evaluationCount == 2) score = score + 300;
                        else score = score + 600;
                    }
                    else
                    {
                        if(evaluationCount == 1)  score = score + 5;
                        else if(evaluationCount == 2) score = score + 600;
                        else score = score + 900;
                    }
                    evaluationCount = 1;

                    /* ****Horizontal right verification**** */
                    for (int i =1; i < 4 ; i++)
                    {
                        if(y +i < 7)
                        {
                            if(board.getCase(x,y) == player && board.getCase(x,y) == board.getCase(x,y+i))
                            {
                                alreadyEvaluated.push_back(Move(x,y+i));
                                evaluationCount++;
                            }
                            else
                            {
                                break;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }


                    /* ****Horizontal left verification**** */
                    for (int i =1; i < 4 ; i++)
                    {
                        if(y - i >= 0 )
                        {
                            if(board.getCase(x,y) == player && board.getCase(x,y) == board.getCase(x,y-i))
                            {
                                alreadyEvaluated.push_back(Move(x,y-i));
                                evaluationCount++;
                            }
                            else
                            {
                                break;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }


                    if(player == 2)
                    {
                        if(evaluationCount == 1)  score = score + 5;
                        else if(evaluationCount == 2) score = score + 300;
                        else score = score + 600;
                    }
                    else
                    {
                        if(evaluationCount == 1)  score = score + 5;
                        else if(evaluationCount == 2) score = score + 600;
                        else score = score + 900;
                    }
                    evaluationCount = 1;


                    /* ****oblical down right verification**** */
                    for (int i =1; i < 4 ; i++)
                    {
                        if(y + i < 7 && x + i < 6)
                        {
                            if(board.getCase(x,y) == player && board.getCase(x,y) == board.getCase(x+i,y+i))
                            {
                                alreadyEvaluated.push_back(Move(x+i,y+i));
                                evaluationCount++;
                            }
                            else
                            {
                                break;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }


                    /* ****Oblical Up left verification**** */
                    for (int i =1; i < 4 ; i++)
                    {
                        if(y - i >= 0 && x - i  >= 0 )
                        {
                            if(board.getCase(x,y) == player && board.getCase(x,y) == board.getCase(x-i,y-i))
                            {
                                alreadyEvaluated.push_back(Move(x-i,y-i));
                                evaluationCount++;
                            }
                            else
                            {
                                break;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }

                    if(player == 2)
                    {
                        if(evaluationCount == 2)  score = score + 5;
                        else if(evaluationCount == 2) score = score + 300;
                        else score = score + 600;
                    }
                    else
                    {
                        if(evaluationCount == 1)  score = score + 5;
                        else if(evaluationCount == 2) score = score + 600;
                        else score = score + 900;
                    }
                    evaluationCount = 1;

                    /* ****oblical up right verification**** */
                    for (int i =1; i < 4 ; i++)
                    {
                        if(y + i < 7 && x - i >= 0)
                        {

                            if(board.getCase(x,y) == player && board.getCase(x,y) == board.getCase(x-i,y+i))
                            {
                                alreadyEvaluated.push_back(Move(x-i,y+i));
                                evaluationCount++;
                            }
                            else
                            {
                                break;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }


                    /* ****Oblical Down left verification**** */
                    for (int i =1; i < 4 ; i++)
                    {
                        if(y - i >= 0 && x + i  < 6 )
                        {

                            if(board.getCase(x,y) == player && board.getCase(x,y) == board.getCase(x+i,y-i))
                            {
                                alreadyEvaluated.push_back(Move(x+i,y-i));
                                evaluationCount++;
                            }
                            else
                            {
                                break;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }

                    if(player == 2)
                    {
                        if(evaluationCount == 2)  score = score + 5;
                        else if(evaluationCount == 2) score = score + 300;
                        else score = score + 600;
                    }
                    else
                    {
                        if(evaluationCount == 1)  score = score + 5;
                        else if(evaluationCount == 2) score = score + 600;
                        else score = score + 900;
                    }
                    evaluationCount = 1;
            }

        }

    }
    evaluationCount = 1;
    return score;

}








bool IA::alreadyExists(vector<Move> moves, Move move)
{
    int taille = moves.size();
    for(int i =0 ; i< taille ; i++)
    {
        if(moves[i].getX() == move.getX() && moves[i].getY() == move.getY())
             return true;
    }
    return false;
}



