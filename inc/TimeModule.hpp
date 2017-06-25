#ifndef TIME_MODULE_CLASS_H
# define TIME_MODULE_CLASS_H

# include <string>
# include <iostream>
# include <DisplayBlock.hpp>
# include <IMonitorModule.hpp>

class TimeModule : public IMonitorModule{
public:
	TimeModule(void);
	TimeModule(TimeModule const & src);
	~TimeModule(void);

	TimeModule & operator=(TimeModule const & rhs);

	DisplayBlock getDisplayInfo(void);

private:
};
#endif
