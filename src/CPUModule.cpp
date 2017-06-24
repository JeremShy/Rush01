#include <CPUModule.hpp>
#include <stdint.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <stdlib.h>
#include <sstream>
#include <time.h>

CPUModule::CPUModule(void) {

}

CPUModule::CPUModule(CPUModule const & src) {

}

CPUModule::~CPUModule(void) {

}

CPUModule & CPUModule::operator=(CPUModule const & rhs) {
	return (*this);
}

DisplayBlock CPUModule::getDisplayInfo(void) const {
	char buffer[512];
	size_t		size;

	size = 512;
	if (sysctlbyname("machdep.cpu.brand_string", buffer, &size, NULL, 0 ) == -1)
	{
		//TODO: Handle Error.
	}
	std::string cpu_brand_string(buffer);
	std::cout << "CPU Brand String: " << cpu_brand_string << std::endl;

	int32_t intbuffer;
	size = sizeof(intbuffer);
	if (sysctlbyname("hw.logicalcpu", &intbuffer, &size, NULL, 0) == -1)
	{
		//TODO: Handle Error.
	}
	std::stringstream ss;
	ss << intbuffer;
	std::string cpu_nbr_logical(ss.str());
	std::cout << "Number of logical cpu : " << cpu_nbr_logical << std::endl;

	if (sysctlbyname("hw.physicalcpu", &intbuffer, &size, NULL, 0) == -1)
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

}
