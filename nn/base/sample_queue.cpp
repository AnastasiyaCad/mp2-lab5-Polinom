#include <iostream>
#include <string>
#include <list>
#include "TPolinom.h"


using namespace std;

int main()
{
	string expression1, expression2;
	double res;

	setlocale(LC_ALL, "Russian");
	cout << "Enter first polynomial: ";
	cin >> expression1;
	cout << "Enter second polynomial: ";
	cin >> expression2;
	TPolinom mypl2(expression2), mypl1(expression1), mypl3;
	cout << "E";
	//TPolinom mypl2("x9y9+xy+1"), mypl1("x8y8+x3y3+xy+27"), mypl3;
	mypl1.ToMonom();
	cout << "E";
	mypl2.ToMonom();
	cout << "E";
	cout << mypl1 + mypl2;
}
