#ifndef STUDENTS_H
#define STUDENTS_H
#include <string> 
#include "QuadraticEq.h"


class Student 
{
public:
	explicit Student(std::string name) : _name(name) {};
	std::string getName() const;
	virtual Solution Solve(QuadraticEq& eqn) const = 0;
	virtual ~Student() {};
private:
	std::string _name;
};


class BadStudent : public Student 
{
public:
	BadStudent(std::string name) : Student(name) {};
	Solution Solve(QuadraticEq& eqn) const override;

};


class GoodStudent : public Student 
{
public:
	GoodStudent(std::string name) : Student(name) {};
	Solution Solve(QuadraticEq& eqn) const override;
};


class AverageStudent : public Student 
{
public:
	AverageStudent(std::string name) : Student(name) {};
	Solution Solve(QuadraticEq& eqn) const override;
};

#endif