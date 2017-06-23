#include "OsInfoModule.hpp"
#include <sys/utsname.h>

OsInfoModule::OsInfoModule(void) {

}

OsInfoModule::OsInfoModule(OsInfoModule const & src) {

}

OsInfoModule::~OsInfoModule(void) {

}

OsInfoModule & OsInfoModule::operator=(OsInfoModule const & rhs) {
	return (*this);
}

DisplayBlock OsInfoModule::getDisplayInfo(void) const {
	struct utsname vuname;

	uname(&vuname);
	std::string sysname(vuname.sysname);
	std::string nodename(vuname.nodename);
	std::string release(vuname.release);
	std::string version(vuname.version);
	std::string machine(vuname.machine);

	std::cout << "sysname: " << sysname << std::endl << "nodename : " << nodename << std::endl << "release : " << release << std::endl << "version : " << version << std::endl << "machine : " << machine << std::endl;
}
