#include "SquareMemento.h"

ostream& operator<<(ostream& out, const SquareMemento& memento)
{
    out << memento.basic << "\n";
    out << memento.width << "\n";
    return out;
}

istream& operator>>(istream& in, SquareMemento& memento)
{
    in >> memento.basic;
    in >> memento.width;
    return in;
}
