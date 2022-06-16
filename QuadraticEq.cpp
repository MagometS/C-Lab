#include "QuadraticEq.h"
const double eps = 1e-8;

Solution QuadraticEq::Solve() const 
{
	double x_1 = 0;
	double x_2 = 0;
	if (abs(_a) < eps) 
	{
		if (abs(_b) < eps) 
		{
			return { 0,0,0 };
		}
		x_1 = -_c / _b;
		x_2 = -_c / _b;
		return { 1,x_1,x_2 };
	}
	double discr = _b * _b - 4 * _a * _c;
	if (discr < 0) 
	{
		return { 0,0,0 };
	}
	x_1 = (-_b + sqrt(discr)) / (2 * _a);
	x_2 = (-_b - sqrt(discr)) / (2 * _a);
	return { 2, x_1,x_2 };
}

std::istream& operator>> (std::istream& is, QuadraticEq& eqn) 
{
	is >> eqn._a >> eqn._b >> eqn._c;
	return is;
}

bool Solution:: operator== (const Solution& to_compare) 
{
	return ((this->_root_count == to_compare._root_count) && (this->_x1 == to_compare._x1) && (this->_x2 == to_compare._x2));
}