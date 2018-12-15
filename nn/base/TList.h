#ifndef __TLIST_H__
#define __TLIST_H__

#include<iostream>
#include<cstdlib>
#include<iterator>
#include <string>

const int MAXSIZE = 1000;

template <class T>
class TList
{
	/*struct Monom
	{
		T coef;
		int degree;
	};*/
	template <class T>
	struct link
	{
		T data; //T
		link *pNext;
		link(T _data = {}, link *_pNext = nullptr)
		{
			data = _data;
			pNext = _pNext;
		}
	};
	link<T> *pFirst;//– указатель на первое звено списка;
	link<T> *pLast; //указатель на последнее звено списка;
	link<T>*pCurrLink; //– указатель на текущее звено списка;
	link<T>*pPrevLink; //– указатель на звено, предшествующее текущему;
	int CurrPos; //– номер текущего звена;
	int ListLen; //-количество звеньев в списке;


public: 
	TList(){
		pFirst = nullptr;
		pCurrLink = nullptr;
		ListLen = 0;
	}
	TList(const TList<T> &l)
	{
		this->pFirst = nullptr;
		this->ListLen = 0;
		link<T>*coont = l.pFirst;
		while (count != nullptr)
		{
			this->Push(count - data);
			count = count->pNext;
		}
		//p->data.coef = 0;
		//p->data.degree = -1;
		//p->pNext = pFirst;
		//pFirst = p;
	}

	~TList()
	{
		link *p = pFirst;
		while (p != nullptr)
		{
			pFirst = p->pNext;
			delete p;
			p = pFirst;
		}
	}
	TList<t>& operator = (const TList<T> & l)
	{
		link<T>*count = l.pFirst;
		if (!this->Empty())
			this->Clear();
		while (count != nullptr)
		{
			this->Push(count->data);
			count = count->pNext;
		}
		return *this;
	}
	
	void Clear()
	{
		while (ListLen != 0)
			Pop();
	}

	bool Empty()
	{
		return pFirst == nullptr;
	}

	/*bool IsFull()
	{
		true
		{
			link *p = new link;
		}
		//return pFirst == ;
	}*/

	T Pop()
	{
		if (!Empty())
			throw "ERROR";
		T d = pFirst->data;
		link<T> *p = pFirst;
		pFirst = pFirst->pNext;
		delete p;
		ListLen--;
		return d;
	}

	void Push(T d)
	{
		if (Empty())
		{
			link *p = new link;
			p->data = d;
			p->pNext = pFirst;
			pFirst = p;
			pCurrLink = pFirst;
			ListLen++;
		}
		else
		{
			if (ListLen == MAXSIZE)
				throw "Error! Maxsize.";
			pCurrLink->pNext = new link;
			pCurrLink = pCurrLink->pNext;
			ListLen++;
		}
	}

	int GetSize()
	{
		return ListLen;
	}
	


	/*void Push(T coef, int degree)
	{
		if (IsFull())
			throw "ERROR";
		link *p = new link;
		p->data.coef = coef;
		p->data.degree = degree;
		p->pNext = pFirst;
		pFirst = p;
	}*/

	//void 
};
#endif
