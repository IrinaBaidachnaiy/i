#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

using namespace std;
using namespace sf;

class Memento
{
	friend class Rectangle;
	friend class Square;
	friend class Composite;
protected:
	int x, y;
	Color color;
public:
	friend ostream& operator<< (ostream& out, const Memento& memento);
	friend istream& operator>> (istream& in, Memento& memento);
};

