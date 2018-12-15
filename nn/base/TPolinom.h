#ifndef __TJOBSTREAM_H__
#define __TJOBSTREAM_H__


#include<iostream>
#include<cstdlib>
#include<iterator>

#include "TList.h"


using namespace std;


class TPolinom
{ 
	struct Monom
	{
		int koef;
		int degree;
		string name;
		Monom(int _koef = 1, int _degree = 0)
		{
			koef = _koef;
			degree = _degree;
		}
		Monom operator +(const Monom &m)
		{
			if (this->degree != m.degree)
				throw "incorrect addition";
			Monom tmp;
			tmp.koef = this->koef + m.koef;
			tmp.degree = this->degree;
			tmp.name = this->name;
			return tmp;
		}
		Monom operator -(const Monom &m)
		{
			if (this->degree != m.degree)
				throw "incorrect addition";
			Monom tmp;
			tmp.koef = this->koef - m.koef;
			tmp.degree = this->degree;
			tmp.name = this->name;
			return tmp;
		}
	};
	TList<Monom> Polinom;
	string startpolinom;

public:
	TPolinom(string i = " ") { startpolinom = i; }
	TPolinom(const TPolinom & pl);
	string StartPolinom() { return startpolinom; }
	void ToMonom(string startpolinom);
	bool Operand(char op);
	bool XYZ(char op);
	bool IsOperation(char elem);
	float Coef(char elem);
	void Space(string str);
	void Split(string elem);
	int DegreePr(char elem);
	bool Proverka(string str);
	void Same(TList<float> list);
};

#endif