#ifndef DISPLAY_BLOCK_CLASS_H
# define DISPLAY_BLOCK_CLASS_H

# include <string>
# include <iostream>

class DisplayBlock {
public:
	DisplayBlock(void);
	DisplayBlock(DisplayBlock const & src);
	~DisplayBlock(void);

	DisplayBlock & operator=(DisplayBlock const & rhs);

private:
};
#endif
