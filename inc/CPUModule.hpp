#ifndef CPUMODULE_CLASS_H
# define CPUMODULE_CLASS_H

# include <string>
# include <iostream>
# include <IMonitorModule.hpp>
# include <Timer.hpp>

class CPUModule : public IMonitorModule{
public:
	CPUModule(void);
	CPUModule(CPUModule const & src);
	~CPUModule(void);

	CPUModule & operator=(CPUModule const & rhs);

	DisplayBlock getDisplayInfo(void);

private:
	Timer _timer;
	clock_t	_old_clock_time;
};
#endif
