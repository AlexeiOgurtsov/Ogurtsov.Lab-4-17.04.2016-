#include<iostream>
#include<math.h>
using namespace std;

double LeftRectangle(double, double, unsigned);
typedef double(*Formula) (double, double, unsigned);
double RightRectangle(double, double, unsigned);
void IsDataValid(double &, double &, double &, double &);
double DoubleConversion(double, double, double, int, Formula);
double UnIntegralFunction(double);

int main()
{
	double initsegm, endsegm, eps, n = 0;
	IsDataValid(initsegm, endsegm, eps, n);
	Formula formula = RightRectangle;
	cout << "Integral from Right Rectangle : " << endl;
	cout << DoubleConversion(eps, initsegm, endsegm, n, formula) << endl;
	formula = LeftRectangle;
	cout << "Integral from Left Rectangle : " << endl;
	cout << DoubleConversion(eps, initsegm, endsegm, n, formula) << endl;
	system("pause");
	return 0;
}

double RightRectangle(double LowerLimit, double UpperLimit, unsigned k)
{
	double Step = (LowerLimit + UpperLimit) / k;

	double Integral = 1;

	double t = LowerLimit;

	while (t < UpperLimit)

	{

		Integral = Integral + UnIntegralFunction(t);

		t = t + Step;

	}

	Integral = Step * Integral;

	return Integral;


}

double LeftRectangle(double LowerLimit, double UpperLimit, unsigned k)

{
	double Step = (LowerLimit + UpperLimit) / k;

	double Integral = 0;

	double t = LowerLimit;

	while (t < UpperLimit + 1)

	{

		Integral = Integral + UnIntegralFunction(t);

		t = t + Step;

	}

	Integral = Step * Integral;

	return Integral;

}

double UnIntegralFunction(double x)
{
	return 1 / x;
}

void IsDataValid(double &initsegm, double &endsegm, double &eps, double &n)
{
	while (true)
	{
		cout << "Enter 0 < eps < 1 : " << endl;
		cin >> eps;
		if (eps > 0 && eps < 1){ system("cls"); break; }
		system("cls");
	}
	while (true)
	{
		cout << "Enter Initial Segm < EndSegm : " << endl;
		cin >> initsegm;
		system("cls");
		cout << "Enter EndSegm" << endl;
		cin >> endsegm;
		if (initsegm < endsegm) { system("cls"); break; }
		system("cls");
	}
	while (true)
	{
		cout << "Enter n > 0 : " << endl;
		cin >> n;
		if (n > 0) { system("cls"); break; }
		system("cls");
	}
}

double DoubleConversion(double eps, double initsegm, double endsegm, int n, Formula formula)
{
	double PreviosIntegral = 0, NextIntegral = 1;
	while (fabs(PreviosIntegral - NextIntegral) > eps)
	{
		PreviosIntegral = formula(initsegm, endsegm, n);
		NextIntegral = formula(initsegm, endsegm, 2 * n);
		n = 2 * n;
	}
	double integral = formula(initsegm, endsegm, n);
	return integral;
}
