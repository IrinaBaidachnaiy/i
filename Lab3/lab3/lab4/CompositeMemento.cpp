#include "CompositeMemento.h"

ostream& operator<<(ostream& out, const CompositeMemento& memento)
{
    out << memento.basic;
    for (int i = 0; i < memento.figures.size(); i++) {
        if (memento.figures[i]->get_figure_type() == "square") {
            SquareMemento mem;
            Square* fig = (Square*)memento.figures[i];
            fig->get_memento(mem);
            out << mem;
        }
        else if (memento.figures[i]->get_figure_type() == "rectangle") {
            RectangleMemento mem;
            Rectangle* rect = (Rectangle*)memento.figures[i];
            rect->get_memento(mem);
            out << mem;
        }
    }
    return out;
}

istream& operator>>(istream& in, CompositeMemento& memento)
{
    in >> memento.basic;
    for (int i = 0; i < memento.figures.size(); i++) {
        if (memento.figures[i]->get_figure_type() == "square") {
            SquareMemento mem;
            Square* fig = (Square*)memento.figures[i];
            in >> mem;
            fig->set_memento(mem);
        }
        else if (memento.figures[i]->get_figure_type() == "rectangle") {
            RectangleMemento mem;
            Rectangle* rect = (Rectangle*)memento.figures[i];
            in >> mem;
            rect->set_memento(mem);
        }
    }
    return in;
}
