#include"TList.h"
#include"TPolinom.h"

TPolinom::TPolinom(const TPolinom & pl)
{
	this->startpolinom = pl.startpolinom;
	this->Polinom = pl.Polinom;
}

void TPolinom::ToMonom()
{
	int c = 0;
	string tmp;
	Monom m = {};
	TList<Monom>::iterator it;
	bool sing = true;
	int degree;
	for (int i = 0; i < startpolinom.size(); i++)
	{
		if (IsOperation(startpolinom[i]))
		{
			if (startpolinom[i] == '+')
				sing = true;
			else
				sing = false;
			i++;
		}
		if (!IsOperation(startpolinom[i]) && !XYZ(startpolinom[i]))
		{
			while (!XYZ(startpolinom[i]) && i != startpolinom.size() && !IsOperation(startpolinom[i]))
			{
				tmp += startpolinom[i];
				i++;
			}
			m.koef = atof(tmp.c_str());
			tmp = "";
			if (!sing)
				m.koef = m.koef*(-1);
		}
		c = i;
		if (XYZ(startpolinom[i]))
		{
			int degree = 0;
			int x = 0, y = 0, z = 0;
			while (!IsOperation(startpolinom[i]) && i != startpolinom.size())
			{
				switch (startpolinom[i]) {
				case '1':
				{
					char s = startpolinom[i + 1];
					x = 100 * (int)s;
					i++;
					break;
				}
				case '2':
				{
					char s = startpolinom[i + 1];
					y = 10 * (int)s;
					i++;
					break;
				}
				case '3':
				{
					char s = startpolinom[i + 1];
					i++;
					z = (int)s;
				}
				default:
				{
					i++;
				}
				}
				i--;
				degree = x + y + z;
				m.name = startpolinom.substr(c, i - c + 1);
				m.degree = degree;
			}
		}
		if (Polinom.Empty())
		{
			Polinom.Push(m);
			continue;
		}
		for (it = Polinom.Begin(); it != Polinom.End(); ++it)
		{
			if (m.degree == it->data.degree)
			{
				it->data.koef = it->data.koef + m.koef;
				if (it->data.koef == 0)
					Polinom.Erase(it);
				break;
			}
			if (m.degree > it->data.degree)
			{
				Polinom.Insert(it, m);
				break;
			}
		}
		if (it == Polinom.End())
		{
			Polinom.Push(m);
		}
	}

	/*while (c != startpolinom.size())
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

int TPolinom::Calculate(int _x, int _y, int _z)
{
	int res = 0;
	for (auto it = Polinom.Begin(); it != Polinom.End(); ++it)
	{
		int x = it->data.degree / 100;
		int y = (it->data.degree / 10) % 10;
		int z = it->data.degree % 10;
		res += (pow(_x, x) * pow(_y, y) * pow(_z, z)) * it->data.koef;
	}
	return res;
}

TPolinom TPolinom::operator+(TPolinom & pl)
{
	if (this->Polinom.Empty() || pl.Polinom.Empty())
		throw "ERROR!!";
	TPolinom main, side, result;
	TList<Monom>::iterator it1, it2;
	if (this->Polinom.GetSize() >= pl.Polinom.GetSize())
	{
		main = *this;
		side = pl;
		it1 = this->Polinom.Begin();
		it2 = pl.Polinom.Begin();
	}
	else
	{
		main = pl;
		side = *this;
		it1 = pl.Polinom.Begin();
		it2 = this->Polinom.Begin();
	}
	for (it1; it1 != main.Polinom.End();)
	{
		if (it1->data.degree == it2->data.degree)
		{
			if ((it1->data.koef + it2->data.koef) != 0)
				result.Polinom.Push(*(it1)+*(it2));
			++it1; ++it2;
		}
		else if (it1->data.degree > it2->data.degree)
		{
			result.Polinom.Push(*it1);
			++it1;
		}
		else if (it1->data.degree < it2->data.degree)
		{
			result.Polinom.Push(*it2);
			++it2;
		}
	}
	while (it2 != side.Polinom.End())
	{
		result.Polinom.Push(*it2);
		++it2;
	}
	return result;
}
TPolinom TPolinom::operator-(TPolinom & pl)
{
	if (this->Polinom.Empty() || pl.Polinom.Empty())
		throw "ERROR!!";
	TPolinom main, side, result;
	TList<Monom>::iterator it1, it2;
	if (this->Polinom.GetSize() >= pl.Polinom.GetSize())
	{
		main = *this;
		side = pl;
		it1 = this->Polinom.Begin();
		it2 = pl.Polinom.Begin();
	}
	else
	{
		main = pl;
		side = *this;
		it1 = pl.Polinom.Begin();
		it2 = this->Polinom.Begin();
	}
	for (it1; it1 != main.Polinom.End();)
	{
		if (it1->data.degree == it2->data.degree)
		{
			if ((it1->data.koef - it2->data.koef) != 0)
				result.Polinom.Push(*(it1)-*(it2));
			++it1; ++it2;
		}
		else if (it1->data.degree > it2->data.degree)
		{
			result.Polinom.Push(*it1);
			++it1;
		}
		else if (it1->data.degree < it2->data.degree)
		{
			result.Polinom.Push(*it2);
			++it2;
		}
	}
	while (it2 != side.Polinom.End())
	{
		result.Polinom.Push(*it2);
		++it2;
	}
	return result;
}
TPolinom & TPolinom::operator=(const TPolinom & pl)
{
	this->Polinom = pl.Polinom;
	this->startpolinom = pl.startpolinom;
	return *this;
}
bool TPolinom::operator==(const TPolinom & pl)const
{
	if (this->startpolinom == pl.startpolinom)
		return true;
	else return false;
}
ostream & operator<<(ostream & os, TPolinom & pl)
{
	if (pl.Polinom.Empty())
		os << pl.startpolinom;
	else
	{
		for (auto it = pl.Polinom.Begin(); it != pl.Polinom.End(); ++it)
		{
			if (it != pl.Polinom.Begin() && it->data.koef > 0)
				os << '+';
			if (it->data.koef != 1)
				os << it->data.koef;
			os << it->data.name;
		}
	}
	return os;
}
istream & operator>>(istream & is, TPolinom & pl)
{
	is >> pl.startpolinom;
	return is;
}