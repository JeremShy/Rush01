#include <main.hpp>
#include <unistd.h>

int main() {
	HostnameModule a;
	a.getDisplayInfo();

	std::cout << "//////////////////////////////////////////" << std::endl;

	OsInfoModule b;
	b.getDisplayInfo();

	std::cout << "//////////////////////////////////////////" << std::endl;

	TimeModule c;
	c.getDisplayInfo();

	std::cout << "//////////////////////////////////////////" << std::endl;

	CPUModule d;
	sleep(1);
	d.getDisplayInfo();

	MemModule e;
	e.getDisplayInfo();
}
