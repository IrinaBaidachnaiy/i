#include "Memento.h"

ostream& operator<<(ostream& out, const Memento& memento)
{
    out << memento.color.r << "\n";
    out << memento.color.g << "\n";
    out << memento.color.b << "\n";
    out << memento.x << "\n";
    out << memento.y << "\n";
    return out;
}

istream& operator>>(istream& in, Memento& memento)
{
    in >> memento.color.r;
    in >> memento.color.g;
    in >> memento.color.b;
    in >> memento.x;
    in >> memento.y;
    return in;
}