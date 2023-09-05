#include "Rectangle.h"

int Rectangle::get_x()
{
    return x;
}

int Rectangle::get_y()
{
    return y;
}

void Rectangle::draw(RenderWindow& window)
{
    window.draw(shape);
}

void Rectangle::move(Vector2u window_size, float coff, int speed)
{
    shape.move(speed * coff * 3.0f, 0.0f);
    x = shape.getPosition().x;
    y = shape.getPosition().y;
    limit_move(window_size);
}

void Rectangle::limit_move(Vector2u size)
{
    if (shape.getPosition().x >= size.x) set_position(0, shape.getPosition().y);
    else if (shape.getPosition().x <= 0) set_position(size.x, shape.getPosition().y);
    if (shape.getPosition().y >= size.y) set_position(shape.getPosition().x, 0);
    else if (shape.getPosition().y <= 0) set_position(shape.getPosition().x, size.y);
}

FloatRect Rectangle::get_bounds()
{
    return shape.getGlobalBounds();
}

void Rectangle::set_position(int x, int y)
{
    this->x = x;
    this->y = y;
    shape.setPosition(x, y);
}

void Rectangle::set_color(Color color)
{
    this->color = color;
    shape.setFillColor(color);
}

void Rectangle::set_fill_color(Color color)
{
    shape.setFillColor(color);
}

void Rectangle::hide()
{
    switch (hide_flag) {
    case 1:
        shape.setFillColor(Color::Black);
        hide_flag++;
        break;
    case 2:
        shape.setFillColor(color);
        hide_flag--;
        break;
    }
}

void Rectangle::transform()
{
    switch (transform_flag) {
    case 1:
        width -= 30;
        height -= 30;
        transform_flag++;
        break;
    case 2:
        width += 30;
        height += 30;
        transform_flag--;
        break;
    }
    shape.setSize(Vector2f(width, height));
}

void Rectangle::remove(RenderWindow* window)
{
    window->clear();
}

Rectangle* Rectangle::clone()
{
    Rectangle* rect = new Rectangle(width, height, color, x, y);
    return rect;
}

void Rectangle::set_memento(RectangleMemento& memento)
{
    color = memento.basic.color;
    height = memento.height;
    width = memento.width;
    x = memento.basic.x;
    y = memento.basic.y;
    shape.setPosition(x, y);
    shape.setFillColor(get_color());
    shape.setSize(Vector2f(width, height));
}

void Rectangle::get_memento(RectangleMemento& memento)
{
    memento.basic.color = color;
    memento.height = height;
    memento.width = width;
    memento.basic.x = x;
    memento.basic.y = y;
}
