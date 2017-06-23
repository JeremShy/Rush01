#ifndef IMONITOR_MODULE_CLASS_H
# define IMONITOR_MODULE_CLASS_H

# include <string>
# include <iostream>
# include "DisplayBlock.hpp"

class IMonitorModule {
public:
	virtual DisplayBlock getDisplayInfo(void) const;

private:
};
#endif
