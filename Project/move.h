#ifndef MOVE_H
#define MOVE_H

#include <iostream>
#include <vector>
using namespace std;
class Move
{
public:

    /* ****Constructor**** */
    Move(int first = 0 , int second = 0 , int scr = 0);


    /* ****Showing Method**** */
    void showYourself() {cout << x << "  " << y << "  " << score << endl;}


    /* ****Getters and Setters**** */
    int getX() {return x;}
    int getY() {return y;}
    int getScore() {return score;}
    void setX(int a) {x=a;}
    void setY(int a) {y=a;}
    void setScore(int a) {score=a;}


private:
    int x;
    int y;
    int score;
};


#endif // MOVE_H
