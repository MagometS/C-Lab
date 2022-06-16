#ifndef QUADRATICEQ_H
#define QUADRATICEQ_H
#include <cmath>
#include <iostream>



void Interface();
class Solution 
{
public:
	Solution(int root_count, double x1, double x2) : _root_count(root_count), _x1(x1), _x2(x2) {};
	void print(std::ostream& out) const;
	bool operator==(const Solution& to_compare);
private:
	int _root_count;
	double _x1;
	double _x2;
};


class QuadraticEq 
{
public:
	friend std::istream& operator>> (std::istream& is, QuadraticEq& eqn);
	QuadraticEq() : _a(0), _b(0), _c(0) {};
	QuadraticEq(std::istream& in) {
		if (!(in >> _a >> _b >> _c))
			throw std::runtime_error("unable to read coefficients");
	}
	Solution Solve() const;
private:
	double _a;
	double _b;
	double _c;
};

#endif