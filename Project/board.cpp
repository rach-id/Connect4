
#include <vector>
#include <iostream>
#include "ball.h"

Board::Board() : winningCount(0)
{
    // Constructing the board
    board = new int* [6];
    for(int i=0; i< 6 ; i++)
    {
        board[i] = new int[7];
    }
    for(int i=0; i < 6; i++)
    {
        for (int j=0; j<7 ; j++)
        {
            board[i][j] = 0;
        }
    }



}





Board::Board(Board & b)
{

    // Constructing the board
    board = new int* [6];
    for(int i=0; i< 6 ; i++)
    {
        board[i] = new int[7];
    }

    for(int i=0; i < 6; i++)
    {
        for (int j=0; j<7 ; j++)
        {
            board[i][j] = b.getCase(i,j);
        }
    }
}




Board::~Board()
{
    for(int i =0;i < 6; i++)
    {
        delete [] board[i];
    }
}




/* ***************Victory Checker************* */
int Board::checkVictory()
{
    for(int x = 0; x < 6 ;x++)
    {
        for(int y = 0 ; y < 7 ; y++)
        {
            if(board[x][y] == 0) goto checkcheck;
        }
    }
    return -2;
    checkcheck:
    for(int x = 0; x < 6 ;x++)
    {
        for(int y = 0 ; y < 7 ; y++)
        {

            winningCount = 1;


            /* ****Vertical Up verification**** */
            for (int i =1; i < 4 ; i++)
            {
                if(x + i < 6)
                {
                    if((board[x][y]==1 && board[x][y] == board[x+i][y]) || (board[x][y]==2 && board[x][y] == board[x+i][y]))
                    {
                        winningCount++;
                        if(winningCount == 4) {return board[x][y];}
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

            //cout << "Vertical down" << endl;
            for (int i =1; i < 4 ; i++)
            {
                if(x - i >= 0)
                {
                    if((board[x][y]==1 && board[x][y] == board[x-i][y]) || (board[x][y]==2 && board[x][y] == board[x-i][y]))
                    {
                        winningCount++;
                        if(winningCount == 4) {return board[x][y];}
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

            winningCount = 1; // To start the Horizontal verification
            /* ****Horizontal right verification**** */
            for (int i =1; i < 4 ; i++)
            {
                if(y +i < 7)
                {
                    if((board[x][y]==1 && board[x][y] == board[x][y+i]) || (board[x][y]==2 && board[x][i+y] == board[x][y]))
                    {
                        winningCount++;
                        if(winningCount == 4) {return board[x][y];}
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
                    if((board[x][y]==1 && board[x][y] == board[x][y-i]) || (board[x][y]==2 && board[x][y] == board[x][y-i]))
                    {
                        winningCount++;
                        if(winningCount == 4) {return board[x][y];}
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


            winningCount = 1; // To start the oblical verification
            /* ****oblical down right verification**** */
            for (int i =1; i < 4 ; i++)
            {
                if(y + i < 7 && x + i < 6)
                {
                    if((board[x][y]==1 && board[x+i][y+i] == board[x][y]) || (board[x][y]==2 && board[i+x][y+i] == board[x][y]))
                    {
                        winningCount++;
                        if(winningCount == 4) {return board[x][y];}
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
                    if((board[x][y]==1 && board[x-i][y-i] == board[x][y]) || (board[x][y]==2 && board[x-i][y-i] == board[x][y]))
                    {
                        winningCount++;
                        if(winningCount == 4) {return board[x][y];}
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


            winningCount = 1; // To start the other oblical verification

            /* ****oblical up right verification**** */
            for (int i =1; i < 4 ; i++)
            {
                if(y + i < 7 && x - i >= 0)
                {
                    if((board[x][y]==1 && board[x-i][y+i] == board[x][y]) || (board[x][y]==2 && board[x-i][y+i] == board[x][y]))
                    {
                        winningCount++;
                        if(winningCount == 4) {return board[x][y];}
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
                    if((board[x][y]==1 && board[x+i][y-i] == board[x][y]) || (board[x][y]==2 && board[x][y] == board[x+i][y-i]))
                    {
                        winningCount++;
                        if(winningCount == 4) {return board[x][y];}
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
       }
    }

    // No winner Scenario
    winningCount = 1;
    return 0 ;
}






int Board::makeMove(int i, int k)
{
    int m = 0;
    for (int j =5; j >= 0; j--)
    {
        if(board[j][i] == 0)
        {
            board[j][i] = k;
            Move move(j,i,0);
            m = j;
            goto winVerification;
        }
    }
    return -1;
    winVerification:
    return m;

}










void Board::showYourself()
{
    for(int i = 0 ; i < 6 ; i ++)
    {
        for(int j = 0 ; j < 7 ; j++)
        {
            cout << board[i][j] << "  " ;
        }
        cout << endl << endl;
    }

}





















