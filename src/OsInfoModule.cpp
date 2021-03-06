#include <OsInfoModule.hpp>
#include <sys/utsname.h>
#include <TextField.hpp>

OsInfoModule::OsInfoModule(void) {

}

OsInfoModule::OsInfoModule(OsInfoModule const & src) {

}

OsInfoModule::~OsInfoModule(void) {

}

OsInfoModule & OsInfoModule::operator=(OsInfoModule const & rhs) {
	return (*this);
}

DisplayBlock OsInfoModule::getDisplayInfo(void) {
	struct utsname vuname;

	uname(&vuname);
	std::string sysname(vuname.sysname);
	std::string nodename(vuname.nodename);
	std::string release(vuname.release);
	std::string version(vuname.version);
	std::string machine(vuname.machine);

	DisplayBlock ret;
	ret.addField(new TextField("sysname:  " + sysname , 25));
	ret.addField(new TextField("nodename: " + nodename, 25));
	ret.addField(new TextField("release:  " + release, 25));
	ret.addField(new TextField("version:  " + version, 25));
	ret.addField(new TextField("machine:  " + machine, 25));

	// std::cout << "sysname: " << sysname << std::endl << "nodename : " << nodename << std::endl << "release : " << release << std::endl << "version : " << version << std::endl << "machine : " << machine << std::endl;
	return (ret);
}
