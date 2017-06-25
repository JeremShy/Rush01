#ifndef MEMMODULE_CLASS_H
# define MEMMODULE_CLASS_H

# include <string>
# include <iostream>
# include <DisplayBlock.hpp>
# include <IMonitorModule.hpp>

class MemModule : public IMonitorModule{
public:
	MemModule(void);
	MemModule(MemModule const & src);
	~MemModule(void);

	MemModule & operator=(MemModule const & rhs);

	DisplayBlock getDisplayInfo(void);

private:
};
#endif
