#include "functions.h"

vector <Student*> buildList(istream& in) 
{
	vector <Student*> student_list;
	while (!in.eof()) 
	{
		string name;
		getline(in, name);
		switch (rand() % 3) 
		{
		case 0:
			student_list.push_back(new BadStudent(name));
			break;
		case 1:
			student_list.push_back(new AverageStudent(name));
			break;
		case 2:
			student_list.push_back(new BadStudent(name));
			break;
		}
	}
	return student_list;
}
queue <tuple <QuadraticEq, Solution, string>> buildQueue(vector <Student*>& list, vector <QuadraticEq>& equations) 
{
	queue <tuple <QuadraticEq, Solution, string>> answers;
	for (auto it_stud : list) 
	{
		for (auto& it_eq : equations) 
		{
			Solution sol = it_stud->Solve(it_eq);
			answers.push({ it_eq, sol, it_stud->getName() });
		}
	}
	return answers;
}
vector <QuadraticEq> readEquations(istream& in) 
{
	vector <QuadraticEq> equations;
	while (!in.eof()) 
	{
		QuadraticEq tmp;
		in >> tmp;
		equations.push_back(tmp);
	}
	return equations;
}

void Interface()
{
	srand(time(0));
	ifstream l("list.txt");
	ifstream eq("input.txt");
	vector <Student*> students = buildList(l);
	vector <QuadraticEq> equations = readEquations(eq);
	auto answers = buildQueue(students, equations);
	map <string, int> results;
	Teacher prepod(results);
	prepod.review(answers);
	prepod.publishResults();
	return;
}