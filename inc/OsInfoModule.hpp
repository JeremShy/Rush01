#ifndef OSINFOMODULE_CLASS_H
# define OSINFOMODULE_CLASS_H

# include <string>
# include <iostream>
# include <DisplayBlock.hpp>

class OsInfoModule {
public:
	OsInfoModule(void);
	OsInfoModule(OsInfoModule const & src);
	~OsInfoModule(void);

	OsInfoModule & operator=(OsInfoModule const & rhs);

	DisplayBlock getDisplayInfo(void) const;

private:
};
#endif
