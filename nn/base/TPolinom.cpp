#include"TList.h"
#include"TPolinom.h"

TPolinom::TPolinom(const TPolinom & pl)
{
	this->startpolinom = pl.startpolinom;
	this->Polinom = pl.Polinom;
}

void TPolinom::ToMonom(string startpolinom)
{
	int c = 0;
	string tmp;
	int degree;
	while (c != startpolinom.size())
	{
		if (IsOperation(startpolinom[c]))
		{
			if (startpolinom[c] == '-')
				tmp += startpolinom[c];
			else
				if (c == 0)
					throw "ERROR! Frist element is operation!";
			c++;
		}
		while (!IsOperation(startpolinom[c]))
		{
			tmp += startpolinom[c];
			c++;
		}
		if (IsOperation(startpolinom[c]))
		{
			int a = 0;
			string num;
			tmp += ' ';
			// проверка на стандарт
			while (!XYZ(tmp[a]))
			{
				num += tmp[a];
				a++;
			}
			degree = 0;
			if (((XYZ(tmp[a - 1]) || (Operand(tmp[a - 1])) && ((XYZ(tmp[a]) && (XYZ(tmp[a + 1]) || tmp[a + 1] == ' '))))))
			{
				//a элементу ставим стпень 1
			}
			if ((XYZ(tmp[a - 1])) && (Operand(tmp[a])) && ((XYZ(tmp[a + 1])) || (IsOperation(tmp[a + 1]))))
			{
				int st = DegreePr(tmp[a - 1]);
				switch (st) {
				case '0': {
					throw "ERROR! Operand don`t xyz!";
					break; }
				case '1':
				{
					degree += 100 * st;
					break;
				}
				case '2':
				{
					degree += 10 * st;
					break;
				}
				case '3':
				{
					degree += st;
				}
				}
			}
		/*	Monom m;
			m.coef = atof(tmp.c_str());
			m.degree = degree;
			Polinom.Push(m);*/
			//запихиваем в моном степень и коэффициент

		}
	}
}
/*
if (IsOperation(startpolinom[i]))////////////////////////////////////////////
		{
			if (startpolinom[i] == '-')
				tmp += startpolinom[i];
			else
				if (i == 0)
					throw "ERROR! Frist element is operation!";
			c++;
		}
*/

void TPolinom::Same(TList list)
{
	for (int i = 0; i < str.size(); i++)
	{
		for (int j = 0; j < str.size(); j++)
		{
			if (str)
		}
	}
}

void TPolinom::Split(string str)
{
	if ()
}

int TPolinom::DegreePr(char op)
{
	if (op == 'x')
		return 1;
	if (op == 'y')
		return 2;
	if (op == 'z')
		return 3;
	return 0;
}

void TPolinom::Space(string str) // удаление пробелов и добавление своего в конце
{
	string tmp;
	for (int i = 0; i < str.size(); i++)
		if (str[i] == ' ')
			continue;
	tmp += ' ';
	startpolinom = tmp;
}

float TPolinom::Coef(char elem)
{
	string tmp;
	int i = 0;
	while (!XYZ(startpolinom[i]))
	{
		tmp += startpolinom[i];
		i++;
	}
	float a = atof(tmp.c_str());
	return a;
}

bool TPolinom::IsOperation(char elem)
{
	return ( elem == '+' || elem == '-' ) ? true : false;
}

bool TPolinom::XYZ(char op)
{
	if ((op == 'x') || (op == 'y') ||(op == 'z'))
		return true;
	else
		return false;
}
bool TPolinom::Operand(char op)
{
	for (char i = '0'; i <= '9'; i++)
		if (op == i)
			return true;
	if (op == '.')
		return true;
	return false;
	/*string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < chars.length(); i++)
	{
		if (op == chars[i])
			return true;
	}
	return false;*/
}

bool TPolinom::Proverka(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (!Operand(str[i]) || (!XYZ(str[i])) || (!IsOperation(str[i])))
		{
			throw "ERROR!!!";
		}
	}
	
}