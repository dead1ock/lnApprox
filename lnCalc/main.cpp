#include <iostream>
#include <iomanip>
#include <math.h>

int getUpperLimit();
int getSelection();
void printResults(double x, double value);

double getTrapizoidApproximation(double upperLimit, int n);
double getMidpointApproximation(double upperLimit, int n);
double getSimpsonsApproximation(double upperLimit, int n);

using namespace std;

void main()
{
	cout << "=======================================================" << endl;
	cout << "\t\tln(x) Calculator" << endl;
	cout << "=======================================================" << endl << endl;

	int selection = getSelection();

	while (selection != 5)
	{
		double value = 0;
		int n = 0;
		int upperLimit = getUpperLimit();

		if (selection == 1 || selection == 4) { // Midpoint
			cout << "== Midpoint ==" << endl;
			double a = pow(10, 4);
			double b = pow(upperLimit - 1, 3);
			double c = 2;
			n = floor(sqrt(double(a*b*c) / double(24.0f)));
			printResults(upperLimit, getMidpointApproximation(upperLimit, n));
			cout << endl;
		}
		if (selection == 2 || selection == 4) { // Trapizoid
			cout << "==Trapizoid==" << endl;
			double a = pow(10, 4);
			double b = pow(upperLimit - 1, 3);
			double c = 2;
			n = floor(sqrt(double(a*b*c) / double(12.0f)));
			printResults(upperLimit, getTrapizoidApproximation(upperLimit, n));
			cout << endl;
		}
		if (selection == 3 || selection == 4) { // Simpsons
			cout << "==Simpsons==" << endl;
			double a = pow(10, 4);
			double b = pow(upperLimit - 1, 5);
			double c = 24;
			n = floor(pow(double(a*b*c) / double(180.0f), double(1.0f / 4.0f)));
			printResults(upperLimit, getSimpsonsApproximation(upperLimit, n));
			cout << endl;
		}
		cout << "---------------" << endl << endl;
		selection = getSelection();
		
	}

	return;
}

int getUpperLimit()
{
	int upperBound = 0;

	cout << "Enter an upper limit: ";
	cin >> upperBound;

	return upperBound;
}

void printResults(double x, double value)
{
	cout << "ln(" << x << ") is approximately " << setprecision(9) << value << endl;
	cout << "ln(" << x << ") actual is " << log(x) << "." << endl << "Error = " << setprecision(9) << log(x) - value << endl;
}

int getSelection()
{
	int selection = 0;
	cout << "Select Type (1=Midpoint, 2=Trapizoid, 3=Simpsons, 4=All, 5=Exit): ";
	cin >> selection;

	if (selection < 1 || selection > 5)
	{
		cout << "Invalid selection." << endl;
		return getSelection();
	}

	return selection;
}

double getTrapizoidApproximation(double upperLimit, int n)
{
	double x = 1;
	double value = 0;
	double deltaX = (upperLimit - 1) / double(n);

	value += 1 / (x);
	x += deltaX;
	for (int i = 1; i < n; i++) {
		value += (2 * (1 / x));
		x += deltaX;
	}
	value += 1 / (x);
	value *= deltaX;
	value /= 2;

	return value;
}

double getMidpointApproximation(double upperLimit, int n)
{
	double x = 1;
	double value = 0;
	double deltaX = (upperLimit - 1) / double(n);

	for (int i = 0; i < n; i++) {
		value += 1 / (x + (deltaX / 2));
		x += deltaX;
	}

	value *= deltaX;
	return value;
}

double getSimpsonsApproximation(double upperLimit, int n)
{
	double x = 1;
	double value = 0;
	double deltaX = (upperLimit - 1) / double(n);

	if ((n % 2) != 0) {
		n += 1;
		deltaX = (upperLimit - 1) / double(n);
	}

	value += 1 / (x);
	x += deltaX;

	for (int i = 1; i < n; i++) {
		if ((i % 2) == 0)
			value += 2 * (1 / (x));
		else
			value += 4 * (1 / (x));

		x += deltaX;
	}
	value += 1 / (x);
	value *= deltaX;
	value /= 3;

	return value;
}