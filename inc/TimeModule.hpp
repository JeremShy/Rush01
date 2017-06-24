#ifndef TIME_MODULE_CLASS_H
# define TIME_MODULE_CLASS_H

# include <string>
# include <iostream>
# include <DisplayBlock.hpp>

class TimeModule {
public:
	TimeModule(void);
	TimeModule(TimeModule const & src);
	~TimeModule(void);

	TimeModule & operator=(TimeModule const & rhs);

	DisplayBlock getDisplayInfo(void) const;

private:
};
#endif
