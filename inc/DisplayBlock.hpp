#ifndef DISPLAY_BLOCK_CLASS_H
# define DISPLAY_BLOCK_CLASS_H

# include <string>
# include <iostream>
# include <vector>
# include "AField.hpp"

class DisplayBlock {
public:
	DisplayBlock(void);
	~DisplayBlock(void);
	void												addField(AField *field);
	std::vector<AField*>				getFields(void) const;
	DisplayBlock(DisplayBlock const & src);

private:
	DisplayBlock & operator=(DisplayBlock const & rhs);
	std::vector<AField*>				_fields;
};
#endif
