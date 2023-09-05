#pragma once
#include "Memento.h"
#include <iostream>

using namespace std;

class RectangleMemento
{
	friend class Rectangle;
	Memento basic;
	int width, height;
public:
	friend ostream& operator<< (ostream& out, const RectangleMemento& memento);
	friend istream& operator>> (istream& in, RectangleMemento& memento);
};

