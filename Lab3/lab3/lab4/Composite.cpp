#include "Composite.h"

void Composite::add(Figure* fig)
{
	if (fig->get_figure_type() == "composite") {
		Composite* com = (Composite*)fig;
		com->set_position(x, y);
		composites.push_back(com);
	}
	else {
		composites.push_back(fig);
	}
}

int Composite::get_x()
{
	return x;
}

int Composite::get_y()
{
	return y;
}

void Composite::draw(RenderWindow& window)
{
	for (int i = 0; i < composites.size(); i++) composites[i]->draw(window);
}

void Composite::move(Vector2u window_size, float coff, int speed)
{
	for (int i = 0; i < composites.size(); i++) {
		composites[i]->move(window_size, coff, speed);
	}
}

void Composite::limit_move(Vector2u size)
{
	for (int i = 0; i < composites.size(); i++) composites[i]->limit_move(size);
}

FloatRect Composite::get_bounds()
{
	return composites[0]->get_bounds();
}

void Composite::set_position(int x, int y)
{
	for (int i = 0; i < composites.size(); i++) composites[i]->set_position(x, y);
}

void Composite::set_color(Color color)
{
	color = color;
	for (int i = 0; i < composites.size(); i++) composites[i]->set_color(color);
}

void Composite::set_fill_color(Color color)
{
	for (int i = 0; i < composites.size(); i++) composites[i]->set_fill_color(color);
}

void Composite::hide()
{
	switch (hide_flag)
	{
	case 1:
		for (int i = 0; i < composites.size(); i++) {
			composites[i]->set_fill_color(Color::Black);
		}
		hide_flag++;
		break;
	case 2:
		for (int i = 0; i < composites.size(); i++) {
			composites[i]->set_fill_color(composites[i]->get_color());
		}
		hide_flag--;
		break;
	}
}

void Composite::transform()
{
	switch (transform_flag) {
	case 1:
		for (int i = 0; i < composites.size(); i++) {
			composites[i]->transform();
		}
		transform_flag++;
		break;
	case 2:
		for (int i = 0; i < composites.size(); i++) {
			composites[i]->transform();
		}
		transform_flag--;
		break;
	}
}

void Composite::remove(RenderWindow* window)
{
	for (int i = 0; i < composites.size(); i++) {
		composites[i]->remove(window);
	}
}

Composite* Composite::clone()
{
	Composite* comp = new Composite();
	for (int i = 0; i < composites.size(); i++) {
		Figure* new_figure = nullptr;
		if (composites[i]->get_figure_type() == "square") {
			Square* sq = (Square*)composites[i];
			new_figure = new Square(sq->get_width(), sq->get_color(), sq->get_x(), sq->get_y());
		}
		else if (composites[i]->get_figure_type() == "rectangle") {
			Rectangle* rec = (Rectangle*)composites[i];
			new_figure = new Rectangle(rec->get_width(), rec->get_height(), rec->get_color(), rec->get_x(), rec->get_y());
		}
		else if (composites[i]->get_figure_type() == "composite") {
			Composite* cmp = (Composite*)composites[i];
			new_figure = cmp->clone();
		}
		comp->add(new_figure);
	}
	return comp;
}

void Composite::set_memento(CompositeMemento& memento)
{
	x = memento.basic.x;
	y = memento.basic.y;
	composites = memento.figures;
	set_position(x, y);
}

void Composite::get_memento(CompositeMemento& memento)
{
	memento.basic.x = x;
	memento.basic.y = y;
	memento.figures = composites;
}
