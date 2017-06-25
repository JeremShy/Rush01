#include <MemModule.hpp>
#include <unistd.h>
#include <TextField.hpp>
#include <mach/mach.h>
#include <sstream>

MemModule::MemModule(void) {

}

MemModule::MemModule(MemModule const & src) {

}

MemModule::~MemModule(void) {

}

MemModule & MemModule::operator=(MemModule const & rhs) {
	return (*this);
}

DisplayBlock MemModule::getDisplayInfo(void){
 	vm_statistics_data_t stat;
	mach_msg_type_number_t count = HOST_VM_INFO_COUNT;
	mach_port_t myHost = mach_host_self();

	host_statistics(myHost, HOST_VM_INFO, reinterpret_cast<host_info_t>(&stat), &count);
	double pages_free = static_cast<double>(stat.free_count);
	double pages_active = static_cast<double>(stat.active_count);
	double percentage = (pages_active / (pages_free + pages_active)) * 100.0;

	std::stringstream ss;
	ss << percentage << "%";
	std::string mem_info = ss.str();
	// std::cout << "pages_free : " << pages_free << std::endl;
	// std::cout << "pages_active : " << pages_active << std::endl;
	// std::cout << "mem_info : " << mem_info << std::endl;

	DisplayBlock ret;
	// ret.addField(new TextField("Date: " + date, 25));
	// ret.addField(new TextField("Heure: " + heure, 25));
	// ret.addField(new TextField("pages_free : " + pages_free, 25));
	// ret.addField(new TextField("pages_active : " + pages_active, 25));
	ret.addField(new TextField("Memory usage : " + mem_info, 25));
	return ret;
}
