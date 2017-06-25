#include <main.hpp>
#include <unistd.h>
#include <ncurses.h>
#include <deque>
#include <fstream>

int main(int ac, char **av) {

	if (ac == 1) {
		std::cout << "Usage : " << av[0] << " C|O|M|T|H|" << std::endl;
		std::cout << "With: C: " << "CPU Module" << std::endl;
		std::cout << "With: O: " << "OsInfo Module" << std::endl;
		std::cout << "With: M: " << "Mem Module" << std::endl;
		std::cout << "With: T: " << "Time Module" << std::endl;
		std::cout << "With: H: " << "Hostname Module" << std::endl;
		return (0);
	}

	std::string arg = av[1];
	std::deque<CPUModule*> cpumods;
	std::deque<OsInfoModule*> osmods;
	std::deque<MemModule*> memmods;
	std::deque<TimeModule*> timemods;
	std::deque<HostnameModule*> hostmods;
	std::deque<IMonitorModule*> modules;
	std::deque<DisplayBlock> dec;

	CPUModule* cpumod;
	OsInfoModule* osmod;
	MemModule* memmod;
	TimeModule* timemod;
	HostnameModule* hostmod;

	std::deque<IMonitorModule*>mods;
	for (std::string::iterator i = arg.begin(); i != arg.end(); ++i)
	{
		switch (*i)
		{
			case 'C':
				cpumod = new CPUModule();
				mods.push_back(cpumod);
				cpumods.push_back(cpumod);
				break;
			case 'O':
				osmod = new OsInfoModule();
				mods.push_back(osmod);
				osmods.push_back(osmod);
				break;
			case 'M':
				memmod = new MemModule();
				mods.push_back(memmod);
				memmods.push_back(memmod);
				break;
			case 'T':
				timemod = new TimeModule();
				mods.push_back(timemod);
				timemods.push_back(timemod);
				break;
			case 'H':
				hostmod = new HostnameModule();
				mods.push_back(hostmod);
				hostmods.push_back(hostmod);
				break;
		}
	}
	// _test_histogramfield();
	std::fstream pouet("log.log", std::fstream::out | std::fstream::trunc);
	pouet.close();
	//
	// HostnameModule a;
	// dec.push_back(a.getDisplayInfo());
	//
	// std::cout << "-------------------------------------" << std::endl;
	//
	// OsInfoModule b;
	// dec.push_back(b.getDisplayInfo());
	//
	// std::cout << "-------------------------------------" << std::endl;
	//
	// TimeModule c;
	// dec.push_back(c.getDisplayInfo());
	//
	// CPUModule c2;
	// CPUModule c3;
	// CPUModule c4;
	// CPUModule c5;
	// CPUModule c6;
	// CPUModule c7;
	// CPUModule c8;
	// CPUModule c9;
	//
	// sleep(1);
	//
	// dec.push_back(c2.getDisplayInfo());
	// dec.push_back(c3.getDisplayInfo());
	// dec.push_back(c4.getDisplayInfo());
	// dec.push_back(c5.getDisplayInfo());
	// dec.push_back(c6.getDisplayInfo());
	// dec.push_back(c7.getDisplayInfo());
	// dec.push_back(c8.getDisplayInfo());
	// dec.push_back(c9.getDisplayInfo());

	// std::cout << "-------------------------------------" << std::endl;
	//
	// CPUModule d;
	// sleep(1);
	// dec.push_back(d.getDisplayInfo());
	// std::deque<DisplayBlock>::iterator i = dec.begin() + 3;
	//
	// MemModule e;
	// dec.push_back(e.getDisplayInfo());
	// std::cout << "-------------------------------------" << std::endl;
	//
	NcurseDisplay nc;
	while(1) {
		dec.clear();
		for (std::deque<IMonitorModule*>::iterator it = mods.begin() ; it != mods.end() && (*it) != NULL; ++it)
		{
			dec.push_back((*it)->getDisplayInfo());
		}
		clear();
		nc.display(dec);
		refresh();
		// dec.erase(i);
		// dec.insert(i, d.getDisplayInfo());
		sleep(1);
	}
}
