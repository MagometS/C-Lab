#include "Teacher.h"
#include "QuadraticEq.h"
#include <tuple>
#include <iterator>

void Teacher::review(std::queue < std::tuple <QuadraticEq, Solution, std::string> >& studQueue) 
{
	while (!studQueue.empty()) 
	{
		auto pending = studQueue.front();
		studQueue.pop();
		std::string studentName = std::get<std::string>(pending);
		Solution teacherSol = std::get<QuadraticEq>(pending).Solve();
		if (_results.find(studentName) == _results.end()) 
		{
			_results.insert({ studentName, 0 });
		}
		bool solvedRight = teacherSol == std::get<Solution>(pending);
		std::map <std::string, int> ::iterator it;
		it = _results.find(studentName);
		if (solvedRight) 
		{
			it->second++;
		}
	}
	return;
}

void Teacher::publishResults() 
{
	for (auto it : _results) 
	{
		std::cout << it.first << " solved " << it.second << " tasks" << std::endl;
	}
	return;
}