#pragma once
#include "Composite.h"
#include "CompositeMemento.h"
#include <fstream>

using namespace std;
static CompositeMemento memento;

class CompositeUtils
{
	string filename = "scene.txt";
public:

	void save_state(Composite* composite, int counter);
	int load_state(Composite* composite, int before);
};

