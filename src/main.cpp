#include <main.hpp>
#include <unistd.h>
#include <ncurses.h>

int main() {
	std::vector<DisplayBlock> vec;

	HostnameModule a;
	vec.push_back(a.getDisplayInfo());

	std::cout << "-------------------------------------" << std::endl;

	OsInfoModule b;
	vec.push_back(b.getDisplayInfo());

	std::cout << "-------------------------------------" << std::endl;

	TimeModule c;
	vec.push_back(c.getDisplayInfo());

	std::cout << "-------------------------------------" << std::endl;

	// CPUModule d;
	// sleep(1);
	// vec.push_back(d.getDisplayInfo());

	MemModule e;
	vec.push_back(e.getDisplayInfo());

	NcurseDisplay nc;
	nc.display(vec);
	refresh();
	while(1);
}
