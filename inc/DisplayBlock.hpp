#ifndef DISPLAY_BLOCK_CLASS_H
# define DISPLAY_BLOCK_CLASS_H

# include <string>
# include <iostream>
# include <list>
# include "AField.hpp"

class DisplayBlock {
public:
	DisplayBlock(void);
	~DisplayBlock(void);
	void										addField(AField const & field);
	std::list<AField>				getFields(void) const;

private:
	DisplayBlock(DisplayBlock const & src);
	DisplayBlock & operator=(DisplayBlock const & rhs);
	std::list<AField>				_fields;
};
#endif
