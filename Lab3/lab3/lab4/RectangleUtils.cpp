#include "RectangleUtils.h"

void RectangleUtils::save_state(Rectangle* rectangle, int counter)
{
	ifstream in(filename);
	in.seekg(counter, ios::beg);
	in >> memento;
	rectangle->set_memento(memento);
	in.close();
}

int RectangleUtils::load_state(Rectangle* rectangle, int before)
{
	rectangle->get_memento(memento);
	ofstream out(filename, ios::app);
	out << memento;
	int after = out.tellp();
	int numberOfBytesWritten = after - before;
	rectangle->set_bytes_written(numberOfBytesWritten);
	out.close();
	return after;
}
