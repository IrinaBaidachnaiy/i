#pragma once
#include "Memento.h"
#include "RectangleMemento.h"
#include "SquareMemento.h"
#include "Rectangle.h"
#include "Square.h"
#include "Figure.h"
#include <fstream>

using namespace std;

class CompositeMemento
{
	friend class Composite;
	Memento basic;
	vector<Figure*> figures;
public:
	friend ostream& operator<< (ostream& out, const CompositeMemento& memento);
	friend istream& operator>> (istream& in, CompositeMemento& memento);
};

