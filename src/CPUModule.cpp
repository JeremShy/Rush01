#include <CPUModule.hpp>
#include <stdint.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <stdlib.h>
#include <sstream>
#include <time.h>
#include <Timer.hpp>

CPUModule::CPUModule(void) {
	_timer.start();
}

CPUModule::CPUModule(CPUModule const & src) {

}

CPUModule::~CPUModule(void) {

}

CPUModule & CPUModule::operator=(CPUModule const & rhs) {
	return (*this);
}

DisplayBlock CPUModule::getDisplayInfo(void) {
	char buffer[512];
	size_t		size;

	size = 512;
	if (sysctlbyname("machdep.cpu.brand_string", buffer, &size, NULL, 0 ) == -1)
	{
		//TODO: Handle Error.
	}
	std::string cpu_brand_string(buffer);
	std::cout << "CPU Brand String: " << cpu_brand_string << std::endl;

	int32_t logical_nbr;
	size = sizeof(logical_nbr);
	if (sysctlbyname("hw.logicalcpu", &logical_nbr, &size, NULL, 0) == -1)
	{
		//TODO: Handle Error.
	}
	std::stringstream ss;
	ss << logical_nbr;
	std::string cpu_nbr_logical(ss.str());
	std::cout << "Number of logical cpu : " << cpu_nbr_logical << std::endl;


	int32_t intbuffer;
	if (sysctlbyname("hw.physicalcpu", &logical_nbr, &size, NULL, 0) == -1)
	{
		//TODO: Handle Error.
	}
	ss.str("");
	ss << intbuffer;
	std::string cpu_nbr_physical(ss.str());
	std::cout << "Number of physical cpu : " << cpu_nbr_physical << std::endl;

	int64_t intbuffer2;
	size = sizeof(int64_t);
	if (sysctlbyname("hw.cpufrequency", &intbuffer2, &size, NULL, 0) == -1)
	{
		//TODO: Handle Error.
	}
	ss.str("");
	ss << (static_cast<double>(intbuffer2) / 1e9) << "GHz";
	std::string cpu_frequency(ss.str());
	std::cout << "CPU Clock speed : " << cpu_frequency << std::endl;

	clock_t t = clock();
	clock_t clock_elapsed = t - _old_clock_time;
	_old_clock_time = t;
	clock_t wall_elapsed = _timer.getDiffAsMicros();
	_timer.restart();

	std::cout << "clock_elapsed : " << clock_elapsed << std::endl;
	std::cout << "wall_elapsed  : " << wall_elapsed << std::endl;
	std::cout << "CLOCK PER S : " << CLOCKS_PER_SEC << std::endl;

	double percentage = static_cast<double>(static_cast<double>(clock_elapsed) / static_cast<double>(wall_elapsed) / static_cast<double>(logical_nbr)) * 100.0;
	ss.str("");
	ss << percentage << "%";
	std::string cpu_usage_percentage(ss.str());
	std::cout << "cpu_usage_percentage " << cpu_usage_percentage <<  std::endl;


}
