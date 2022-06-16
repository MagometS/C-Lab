#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <queue>
#include <map>
#include <tuple>
#include <vector>
#include <iterator>
#include <fstream>
#include "Students.h"
#include "Teacher.h"
#include "QuadraticEq.h"

using namespace std;

vector <Student*> buildList(istream& in);
queue <tuple <QuadraticEq, Solution, string>> buildQueue(vector <Student*>& list, vector <QuadraticEq>& equations);
vector <QuadraticEq> readEquations(istream& in);

#endif