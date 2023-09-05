#pragma once
#include "Figure.h"
#include "RectangleMemento.h"

class Rectangle : public Figure
{
	int width, height;
	RectangleShape shape;
public:
	Rectangle() {
		width = height = 0;
		x = y = 0;
		color = Color::Transparent;
	}
	Rectangle(int width, int height, Color c, int x, int y) : Figure(x, y, c, "rectangle") {
		this->width = width;
		this->height = height;
		shape.setSize(Vector2f(width, height));
		shape.setFillColor(color);
		shape.setPosition(x, y);
		shape.setOrigin(width / 2, height / 2);
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
	Rectangle* clone() override;
	void set_memento(RectangleMemento& memento);
	void get_memento(RectangleMemento& memento);
	int get_width() { return width; }
	int get_height() { return height; }
};

