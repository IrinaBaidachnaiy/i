#pragma once
#include "Figure.h"
#include "SquareMemento.h"

class Square : public Figure
{
	int width;
	CircleShape shape;
public:
	Square() {
		width = 0;
	}
	Square(int width, Color color, int x, int y) : Figure(x, y, color, "square") {
		this->width = width;
		shape.setRadius(width);
		shape.setPointCount(4);
		shape.setPosition(x, y);
		shape.setFillColor(color);
	}

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
	Square* clone() override;
	void set_memento(SquareMemento& memento);
	void get_memento(SquareMemento& memento);
	int get_width() { return width; }
};

