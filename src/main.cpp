#include <main.hpp>

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
	d.getDisplayInfo();
}
