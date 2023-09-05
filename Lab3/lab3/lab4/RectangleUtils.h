#pragma once
#include "Rectangle.h"
#include "RectangleMemento.h"
#include <fstream>

using namespace std;

class RectangleUtils
{
	RectangleMemento memento;
	string filename = "scene.txt";
public:
	void save_state(Rectangle* rectangle, int counter);
	int load_state(Rectangle* rectangle, int before);
};

