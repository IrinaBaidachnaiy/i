#pragma once
#include "Memento.h"
#include <iostream>

using namespace std;

class SquareMemento
{
	friend class Square;
	Memento basic;
	int width;
public:
	friend ostream& operator<< (ostream& out, const SquareMemento& memento);
	friend istream& operator>> (istream& in, SquareMemento& memento);
};

