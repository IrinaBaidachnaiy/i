#pragma once
#include "Square.h"
#include "SquareMemento.h"
#include <fstream>

using namespace std;

class SquareUtils
{
	SquareMemento memento;
	string filename = "scene.txt";
public:
	void save_state(Square* square, int counter);
	int load_state(Square* square, int before);
};

