#include "CompositeUtils.h"

void CompositeUtils::save_state(Composite* composite, int counter)
{
	ifstream in(filename);
	in.seekg(counter, ios::beg);
	in >> memento;
	composite->set_memento(memento);
	in.close();
}

int CompositeUtils::load_state(Composite* composite, int before)
{
	composite->get_memento(memento);
	ofstream out(filename, ios::app);
	out << memento;
	int after = out.tellp();
	int numberOfBytesWritten = after - before;
	composite->set_bytes_written(numberOfBytesWritten);
	out.close();
	return after;
}
