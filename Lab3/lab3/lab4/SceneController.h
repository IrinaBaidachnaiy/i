#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <time.h>
#include "Figure.h"
#include "Square.h"
#include "Composite.h"
#include "RectangleUtils.h"
#include "SquareUtils.h"
#include "CompositeUtils.h"

using namespace sf;
using namespace std;

class SceneController
{
protected:
	static SceneController* instance;
	RenderWindow* window;
	vector<Figure*> figures;
	int selected_figure;
	Color colors[5] = { Color::Blue, Color::Yellow, Color::Red, Color::Green, Color::Cyan };
	string fileName;
	SceneController(string _fileName) {
		ContextSettings settings;
		settings.antialiasingLevel = 8;
		window = new RenderWindow(VideoMode(1000, 1000), "CourseWork", Style::Default, settings);
		fileName = _fileName;
	}
	~SceneController() {
		delete instance;
		for (int i = 0; i < figures.size(); i++) {
			delete figures[i];
		}
	}
	void add_figure(Figure* figure) {
		figures.push_back(figure);
	}
	bool collision_check() {
		FloatRect boundingBox = figures[selected_figure]->get_bounds();
		for (int i = 0; i < figures.size(); i++) {
			if (i == selected_figure) continue;
			if (boundingBox.intersects(figures[i]->get_bounds())) {
				return true;
			}
		}
		return false;
	}
public:
	static SceneController* get_instance(string _fileName);
	void menu();
	void start();
};

