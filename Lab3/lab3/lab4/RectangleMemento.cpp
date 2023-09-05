#include "RectangleMemento.h"

ostream& operator<<(ostream& out, const RectangleMemento& memento)
{
    out << memento.basic << "\n";
    out << memento.width << "\n";
    out << memento.height << "\n";
    return out;
}

istream& operator>>(istream& in, RectangleMemento& memento)
{
    in >> memento.basic;
    in >> memento.width;
    in >> memento.height;
    return in;
}
