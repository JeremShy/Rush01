#ifndef DISPLAY_BLOCK_CLASS_H
# define DISPLAY_BLOCK_CLASS_H

# include <string>
# include <iostream>
# include <deque>
# include "AField.hpp"

class DisplayBlock {
public:
	DisplayBlock(void);
	~DisplayBlock(void);
	void												addField(AField *field);
	std::deque<AField*>				getFields(void) const;
	DisplayBlock(DisplayBlock const & src);
	DisplayBlock & operator=(DisplayBlock const & rhs);

private:
	std::deque<AField*>				_fields;
};
#endif
