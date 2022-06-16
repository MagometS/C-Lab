#include "Students.h"

std::string Student::getName() const { return this->_name; }

Solution BadStudent::Solve(QuadraticEq& eqn) const 
{
	return { 1,0,0 };
}
Solution GoodStudent::Solve(QuadraticEq& eqn) const 
{
	return eqn.Solve();
}

Solution AverageStudent::Solve(QuadraticEq& eqn) const 
{
	if (rand() % 2) 
	{
		return eqn.Solve();
	}
	else 
	{
		return { 1,0,0 };
	}
}