//carolina estrada rangel
#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <complex>
#include<iomanip>
using namespace std;

class Quadratic {
private:
	float first_coef;
	float second_coef;
	float third_coef;
	friend string show(Quadratic);
public:

	Quadratic(float a = 0, float b = 0, float c = 0);

	float getfirst_coef();
	float getsecond_coef();
	string roots();
	float getthird_coef();
	string vertex();
	string derivative();
	float integral(double, double);
	Quadratic larger_area(Quadratic, Quadratic, double, double);
	Quadratic overload(Quadratic, Quadratic);
	Quadratic operator + (Quadratic B) {
		Quadratic C;
		C.first_coef = first_coef + B.first_coef;
		C.second_coef = second_coef + B.second_coef;
		C.third_coef = third_coef + B.third_coef;
		return C;
	}

};
Quadratic::Quadratic(float a, float b, float c) {
	first_coef = a;
	second_coef = b;
	third_coef = c;
}

float Quadratic::getfirst_coef() {
	return first_coef;
}
float Quadratic::getsecond_coef() {
	return second_coef;

}
float Quadratic::getthird_coef() {
	return third_coef;
}

string show(Quadratic C) {
	char sign;
	string x2 = "x^2";
	string x = "x";
	if (C.second_coef < 0)
		x2 = "x^2 -";
	if (C.second_coef > 0)
		x2 = "x^2 +";
	if (C.third_coef < 0)
		x = "x -";
	if (C.third_coef > 0)
		x = "x +";
	return  to_string(C.first_coef) + x2 + to_string(abs(C.second_coef)) + x + to_string(abs(C.third_coef));

}
string Quadratic::roots() {
	float real = 0;

	float img = (pow(second_coef, 2) - 4 * first_coef * third_coef);
	if (img >= 0) {
		img = 0;
		real = ((-second_coef - sqrt(abs(pow(second_coef, 2) - 4 * first_coef * third_coef))) / (2 * first_coef));
		return to_string(real) + "+" + to_string(img) + "i" + ", " + to_string(((-second_coef + sqrt(abs(pow(second_coef, 2) - 4 * first_coef * third_coef))) / (2 * first_coef))) + "-" + to_string(img) + "i";

	}
	if (img < 0) {
		//img = 44;
		real = -second_coef / (2 * first_coef);
		img = sqrt(abs(pow(second_coef, 2) - 4 * first_coef * third_coef)) / (2 * first_coef);

		return to_string(real) + "+ " + to_string(img) + "i" + ", " + to_string(real) + " - " + to_string(img) + "i";
	}
	return "0";
}

string Quadratic::vertex() {
	float v = -second_coef / (2 * first_coef);
	float k = -(pow(second_coef, 2) - 4 * first_coef * third_coef) / (4 * first_coef);
	return to_string(v) + "," + to_string(k);
}

string Quadratic::derivative() {
	string new_x = "x";
	if (second_coef > 0)
		new_x = "x + ";
	if (second_coef < 0)
		new_x = " x - ";
	return to_string(first_coef * 2) + new_x + to_string(abs(second_coef));

}
float Quadratic::integral(double a, double b) {

	// basically doing the integration of the quadratic for each coefficient

	float sec_int = (first_coef / 3) * pow(b, 3);
	float sec_secondint = (second_coef / 2) * pow(b, 2);
	float sec_thirdint = (third_coef / 1) * b;
	float sec_fin = sec_int + sec_secondint + sec_thirdint;
	// the equation above takes all three floats from the integral b to then to the same with the other number of integral a

	float new_int = (first_coef / 3) * pow(a, 3);
	float second_int = (second_coef / 2) * pow(a, 2);
	float third_int = (third_coef / 1) * a;
	float fin = new_int + second_int + third_int;
	float integral_flo = sec_fin - fin;
	// doing the math of the interval, so subracting the higher inteveral number with lower nubmer to get the integral number.
	return integral_flo;
}

Quadratic larger_area(Quadratic A, Quadratic B, double a, double b) {

	double a1 = A.integral(a, b);
	double a2 = B.integral(a, b);
	if (a1 > a2)
		return A;
	else
		return B;

}

int main() {
	Quadratic C1(3, -7, 5);
	Quadratic P(1, 8, -3);
	Quadratic J(4, 7, -12);

	cout << show(C1) << endl;
	cout << show(P) << endl;
	cout << C1.getfirst_coef() << endl;

	cout << C1.roots() << endl;
	cout << P.roots() << endl;
	cout << J.roots() << endl;

	cout << P.derivative() << endl;

	cout << C1.vertex() << endl;
	cout << C1.integral(1, 4) << endl;
	cout << P.integral(1, 4) << endl;
	//cout << C1.integral(2, 3) << endl;

	cout << show(C1 + P) << endl;
	Quadratic R = P + C1;

	cout << show(larger_area(P, C1, 1, 4)) << endl;

	//cout << show(C1 - P) << endl;
	return 0;
}
