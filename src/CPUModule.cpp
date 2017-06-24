#include <CPUModule.hpp>
#include <stdint.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <stdlib.h>
#include <sstream>
#include <time.h>
#include <Timer.hpp>
#include <TextField.hpp>
#include <mach/mach.h>

CPUModule::CPUModule(void) {
	_timer.start();
	host_cpu_load_info_data_t stat;
	mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
	mach_port_t myHost = mach_host_self();

	host_statistics(myHost, HOST_CPU_LOAD_INFO, reinterpret_cast<host_info_t>(&stat), &count);
	this->_oldUser = stat.cpu_ticks[CPU_STATE_USER];
	this->_oldSystem = stat.cpu_ticks[CPU_STATE_SYSTEM];
	this->_oldIdle = stat.cpu_ticks[CPU_STATE_IDLE];
	this->_oldAll = _oldUser + _oldSystem + _oldIdle;
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

	host_cpu_load_info_data_t stat;
	mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
	mach_port_t myHost = mach_host_self();

	host_statistics(myHost, HOST_CPU_LOAD_INFO, reinterpret_cast<host_info_t>(&stat), &count);


	DisplayBlock ret;
	std::cout << "state user : " << stat.cpu_ticks[CPU_STATE_USER] << std::endl;
	std::cout << "state system : " << stat.cpu_ticks[CPU_STATE_SYSTEM] << std::endl;
	std::cout << "state nice : " << stat.cpu_ticks[CPU_STATE_NICE] << std::endl;
	std::cout << "state idle : " << stat.cpu_ticks[CPU_STATE_IDLE] << std::endl;
	double user = stat.cpu_ticks[CPU_STATE_USER];
	double system = stat.cpu_ticks[CPU_STATE_SYSTEM];
	double idle = stat.cpu_ticks[CPU_STATE_IDLE];
	double all = user + system + idle;

	double	user_diff = user - this->_oldUser;
	double	system_diff = system - this->_oldSystem;
	double	idle_diff = idle - this->_oldIdle;
	double	all_diff = all - this->_oldAll;

	double p_user = (user_diff / all_diff) * 100.0;
	double p_system = (system_diff / all_diff) * 100.0;
	double p_idle = (idle_diff / all_diff) * 100.0;

	this->_oldUser = user;
	this->_oldSystem = system;
	this->_oldIdle = idle;
	this->_oldAll = all;


	ss.str("");
	ss << p_user << "%";
	std::string sp_user = ss.str();

	ss.str("");
	ss << p_system << "%";
	std::string sp_system = ss.str();

	ss.str("");
	ss << p_idle << "%";
	std::string sp_idle = ss.str();

	std::cout << "sp_user : " << sp_user << std::endl;
	std::cout << "sp_system : " << sp_system << std::endl;
	std::cout << "sp_idle : " << sp_idle << std::endl;

	ret.addField(new TextField(cpu_brand_string, 25));
	ret.addField(new TextField("Logical cpu number: " + cpu_nbr_logical, 25));
	ret.addField(new TextField("physical cpu number: " + cpu_nbr_physical, 25));
	ret.addField(new TextField("Frequency: " + cpu_frequency, 25));
	ret.addField(new TextField("Usage user : " + sp_user, 25));
	ret.addField(new TextField("Usage system : " + sp_system, 25));
	ret.addField(new TextField("Usage idle : " + sp_idle, 25));
	return (ret);
}
