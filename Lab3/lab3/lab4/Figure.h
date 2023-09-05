#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;
using std::string;

class Figure
{
protected:
	int x, y;
	Color color;
	string figure_type;
	int bytes_written;
	bool selected = false;
	int hide_flag = 1;
	int transform_flag = 1;
public:
	Figure() {
		x = y = 0;
		color = Color::Black;
		figure_type = "";
	}
	Figure(string type) {
		this->figure_type = type;
	}
	Figure(int x, int y, Color color, string type) {
		this->x = x;
		this->y = y;
		this->figure_type = type;
		this->color = color;
	}

	virtual int get_x() = 0;
	virtual int get_y() = 0;
	virtual void draw(RenderWindow& window) = 0;
	virtual void move(Vector2u window_size, float coff, int speed) = 0;
	virtual void limit_move(Vector2u size) = 0;
	virtual FloatRect get_bounds() = 0;
	virtual void set_position(int x, int y) = 0;
	virtual void set_color(Color color) = 0;
	virtual void set_fill_color(Color color) = 0;
	virtual void hide() = 0;
	virtual void transform() = 0;
	virtual void remove(RenderWindow* window) = 0;
	virtual Figure* clone() = 0;

	int get_bytes_written() { return bytes_written; }
	void set_bytes_written(int bytes) { bytes_written = bytes; }
	bool get_selected() { return selected; }
	void set_selected(bool selected) { this->selected = selected; }
	string get_figure_type() { return figure_type; }
	Color get_color() { return color; }
};

