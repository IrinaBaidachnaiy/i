#include "Square.h"

FloatRect Square::get_bounds()
{
    return shape.getGlobalBounds();
}

void Square::set_position(int x, int y)
{
    this->x = x;
    this->y = y;
    shape.setPosition(x, y);
}

void Square::set_color(Color color)
{
    this->color = color;
    shape.setFillColor(color);
}

void Square::set_fill_color(Color color)
{
    shape.setFillColor(color);
}

int Square::get_x()
{
    return x;
}

int Square::get_y()
{
    return y;
}

void Square::draw(RenderWindow& window)
{
    window.draw(shape);
}

void Square::move(Vector2u window_size, float move_coff, int speed)
{
    shape.move(speed * move_coff * 3.0f, 0.0f);

    x = shape.getPosition().x;
    y = shape.getPosition().y;
    limit_move(window_size);
}

void Square::limit_move(Vector2u size)
{
    if (shape.getPosition().x >= size.x) set_position(0, shape.getPosition().y);
    else if (shape.getPosition().x <= 0) set_position(size.x, shape.getPosition().y);
    if (shape.getPosition().y >= size.y) set_position(shape.getPosition().x, 0);
    else if (shape.getPosition().y <= 0) set_position(shape.getPosition().x, size.y);
}

void Square::hide()
{
    switch (hide_flag) {
    case 1:
        shape.setFillColor(Color::Black);
        hide_flag++;
        break;
    case 2:
        shape.setFillColor(get_color());
        hide_flag--;
        break;
    }
}

void Square::transform()
{
    switch (transform_flag) {
    case 1:
        width -= 30;
        transform_flag++;
        break;
    case 2:
        width += 30;
        transform_flag--;
        break;
    }
    shape.setRadius(width);
}

void Square::remove(RenderWindow* window)
{
    window->clear();
}

Square* Square::clone()
{
    Square* square = new Square(width, color, x, y);
    return square;
}

void Square::set_memento(SquareMemento& memento)
{
    color = memento.basic.color;
    x = memento.basic.x;
    y = memento.basic.y;
    width = memento.width;
    shape.setRadius(width);
    shape.setPointCount(4);
    shape.setPosition(x, y);
    shape.setFillColor(color);
}

void Square::get_memento(SquareMemento& memento)
{
    memento.basic.color = color;
    memento.basic.x = x;
    memento.basic.y = y;
    memento.width = width;
}
