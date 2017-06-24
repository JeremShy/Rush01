#ifndef HOSTNAME_CLASS_H
# define HOSTNAME_CLASS_H

# include <string>
# include <iostream>
# include <IMonitorModule.hpp>

class HostnameModule : public IMonitorModule{
public:
	HostnameModule(void);
	HostnameModule(HostnameModule const & src);
	~HostnameModule(void);

	HostnameModule & operator=(HostnameModule const & rhs);

	DisplayBlock getDisplayInfo(void);

private:
};
#endif
