#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "figures.h"
template <class T1, class T2> bool isIntersecting(T1& A, T2& B);
void Collission(Racket& racket, std::vector<Ball>& balls);
void Collission(Brick& brick, std::vector<Ball>& balls, Player& player);
void Collission(Racket& racket, Bonus& bonus);
void Collission(Brick& brick, MovingBrick& movingBrick);
void Collission(MovingBrick& movingBrickFirst, MovingBrick& movingBrickSecond);
#endif 