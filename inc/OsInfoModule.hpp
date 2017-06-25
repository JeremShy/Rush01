#ifndef OSINFOMODULE_CLASS_H
# define OSINFOMODULE_CLASS_H

# include <string>
# include <iostream>
# include <DisplayBlock.hpp>
# include <IMonitorModule.hpp>

class OsInfoModule : public IMonitorModule {
public:
	OsInfoModule(void);
	OsInfoModule(OsInfoModule const & src);
	~OsInfoModule(void);

	OsInfoModule & operator=(OsInfoModule const & rhs);

	DisplayBlock getDisplayInfo(void);

private:
};
#endif
