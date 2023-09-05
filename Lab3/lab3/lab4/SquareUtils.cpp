#include "SquareUtils.h"

void SquareUtils::save_state(Square* square, int counter)
{
	ifstream in(filename);
	in.seekg(counter, ios::beg);
	in >> memento;
	square->set_memento(memento);
	in.close();
}

int SquareUtils::load_state(Square* square, int before)
{
	square->get_memento(memento);
	ofstream out(filename, ios::app);
	out << memento;
	int after = out.tellp();
	int numberOfBytesWritten = after - before;
	square->set_bytes_written(numberOfBytesWritten);
	out.close();
	return after;
}
