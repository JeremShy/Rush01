#ifndef CPUMODULE_CLASS_H
# define CPUMODULE_CLASS_H

# include <string>
# include <iostream>
# include <IMonitorModule.hpp>

class CPUModule : public IMonitorModule{
public:
	CPUModule(void);
	CPUModule(CPUModule const & src);
	~CPUModule(void);

	CPUModule & operator=(CPUModule const & rhs);

	DisplayBlock getDisplayInfo(void) const;

private:
};
#endif
