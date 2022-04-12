#include <iostream>
#include <cmath>

using namespace std; 


void GetCoeff(double& a, double& b, double& c);
double Discriminant(double a, double b, double c);

int main()
{
	setlocale(LC_ALL, "Russian");
	double a, b, c;
	GetCoeff(a, b, c);
	cout << a << "," << b << "," << c;

	return 0;
}

//�������� ������������ ����������� ��������� �� ������ �����
void GetCoeff(double& a,double& b, double& c)
{
	cout << "������� ��������� ���� a*x^2 + b*x + c = 0\n\n";
	cout << "������� ����������� a\n";
	cin >> a;
	cout << "������� ����������� b\n";
	cin >> b;
	cout << "������� ����������� c\n";
	cin >> c;
}

//������� ������������
double Discriminant(double a, double b, double c)
{
	return b * b - 4 * a * c;
}

//������� �����
void FindRoots(double* x1, double* x2, double a, double b, double d)
{
	if (d > 0)
	{
		*x1 = (sqrt(d) - b) / (2 * a);
		*x2 = ((-b) - sqrt(d)) / (2 * a);
	}
	if (d == 0)
	{
		*x1 = (-b) / (2 * a);
		*x2 = *x1;
	}
	if (d < 0)
	{
		x1 = NULL;
		x2 = NULL;
	}
}


void PrintResults(double x1, double x2)
{
	if (x1 == NULL)
	{
		cout << "��� �������������� ������" << endl;
		return;
	}
	if (x1 == x2)
	{
		cout << "x = " << x1 << endl;
		return;
	}

	cout << "x1 = " << x1 << endl << "x2 = "<< x2 << endl;
	

}