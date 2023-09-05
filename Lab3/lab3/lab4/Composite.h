#pragma once
#include <vector>
#include "Rectangle.h"
#include "Square.h"
#include "CompositeMemento.h"

using namespace std;

class Composite : public Figure
{
	vector<Figure*> composites;
	int x;
	int y;
	Color color;
public:
	Composite() { x = y = 0; }
	Composite(float x, float y) : Figure("composite") {
		this->x = x;
		this->y = y;
	}

	void add(Figure* fig);
	int get_count() { return composites.size(); }
	void set_x(int x) { this->x = x; }
	void set_y(int y) { this->y = y; }

	int get_x() override;
	int get_y() override;
	void draw(RenderWindow& window) override;
	void move(Vector2u window_size, float coff, int speed) override;
	void limit_move(Vector2u size) override;
	FloatRect get_bounds() override;
	void set_position(int x, int y) override;
	void set_color(Color color) override;
	void set_fill_color(Color color) override;
	void hide() override;
	void transform() override;
	void remove(RenderWindow* window) override;
	Composite* clone() override;
	void set_memento(CompositeMemento& memento);
	void get_memento(CompositeMemento& memento);
};

