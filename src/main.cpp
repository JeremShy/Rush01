#include <main.hpp>
#include <unistd.h>
#include <ncurses.h>
#include <deque>
#include <fstream>

int main() {

	// _test_histogramfield();
	std::fstream pouet("log.log", std::fstream::out | std::fstream::trunc);
	pouet.close();
	std::deque<DisplayBlock> dec;

	HostnameModule a;
	dec.push_back(a.getDisplayInfo());

	std::cout << "-------------------------------------" << std::endl;

	OsInfoModule b;
	dec.push_back(b.getDisplayInfo());

	std::cout << "-------------------------------------" << std::endl;

	TimeModule c;
	dec.push_back(c.getDisplayInfo());

	std::cout << "-------------------------------------" << std::endl;

	CPUModule d;
	// sleep(1);
	dec.push_back(d.getDisplayInfo());

	MemModule e;
	dec.push_back(e.getDisplayInfo());
	std::cout << "-------------------------------------" << std::endl;


	NcurseDisplay nc;
	nc.display(dec);
	refresh();
	while(1);
}
