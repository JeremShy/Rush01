#include "HostnameModule.hpp"
#include <unistd.h>

HostnameModule::HostnameModule(void) {

}

HostnameModule::HostnameModule(HostnameModule const & src) {

}

HostnameModule::~HostnameModule(void) {

}

HostnameModule & HostnameModule::operator=(HostnameModule const & rhs) {
	return (*this);
}

DisplayBlock HostnameModule::getDisplayInfo(void){
	char hostnamech[512];
	char *usernamech;

	if (gethostname(hostnamech, 512) != 0)
	{
		//TODO : Error ;
	}
	if (!(usernamech = getlogin()))
	{
		//TODO: Error
	}

	std::string username(usernamech);
	std::string hostname(hostnamech);

	std::cout << "username : " << username << std::endl << "hostname : " << hostname << std::endl;
}
