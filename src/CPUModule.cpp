#include <CPUModule.hpp>
#include <stdint.h>
#include <sys/types.h>
#include <sys/sysctl.h>


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
}
