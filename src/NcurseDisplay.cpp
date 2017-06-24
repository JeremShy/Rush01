#include <NcurseDisplay.hpp>
#include <display.hpp>

NcurseDisplay::NcurseDisplay(void) {
	// init_ncurse();
}

NcurseDisplay::NcurseDisplay(NcurseDisplay const & src) {
}

NcurseDisplay::~NcurseDisplay(void) {
}

NcurseDisplay & NcurseDisplay::operator=(NcurseDisplay const & rhs) {
	return (*this);
}

void							NcurseDisplay::display(std::vector<DisplayBlock> list) const{
	int xmax = get_size_x();
	int ymax = get_size_y();
	int	xcol = 0;
	int	x = 0;
	int	y = 0;
	std::vector<int> vec(2,0);

	std::vector<DisplayBlock>::iterator iterator;
	for (iterator = list.begin(); iterator != list.end(); iterator++)
	{
		std::cout << "iterating in first for " << std::endl;
		vec = getDisplayBlockSize(*iterator);
		if (vec[0] > xcol) {
			xcol = vec[0];
		}
		if (y + vec[1] > ymax)
		{
			x += xcol;
			y = 0;
			xcol = 0;
		}
		// vec = this->printDisplayBlock(*iterator, x, y);
		x += vec[0];
		y += vec[1];
	}
}

std::vector<int>	NcurseDisplay::getDisplayBlockSize(DisplayBlock block)const  {
	std::cout << "//////////////////////////////////////////////////" << std::endl;
	std::vector<int> ret(2, 0);
	std::vector<int> vec(2, 0);
	int	x = 0;
	int	y = 0;

	std::vector<AField*>::iterator iterator = block.getFields().begin();
	std::vector<AField*>::iterator end = block.getFields().end();


	for (; iterator != end; iterator++)
	{
		std::cout << "Iterating in getDisplayBlockSize" << std::endl;
		vec = (*iterator)->getFieldSizeForNcurse();
		std::cout << "Successfully Returned from getFieldSizeForNcurse" << std::endl;
		std::cout << "vec[0] : " << vec[0] << std::endl;
		std::cout << "vec[1] : " << vec[1] << std::endl;
		y += vec[1];
		if (vec[0] > x)
			x = vec[0];
		std::cout << "End of for of getDisplayBlockSize" << std::endl;
	}
	ret[0] = x;
	ret[1] = y;
	std::cout << "Returning from getDisplayBlockSize" << std::endl;
	std::cout << "//////////////////////////////////////////////////" << std::endl;
	return (ret);
}

std::vector<int>	NcurseDisplay::printDisplayBlock(DisplayBlock block, int x, int y)const  {
	std::vector<int> ret = getDisplayBlockSize(block);
	std::vector<int> vec(2, 0);

	std::vector<AField*>::iterator iterator = block.getFields().begin();
	std::vector<AField*>::iterator end = block.getFields().end();
	ret[0] = 0;
	ret[1] = 0;
	int curx = x;
	int cury = y;
	for (; iterator != end; iterator++) {
		vec = (*iterator)->printFieldForNcurse(curx, cury);
		cury += vec[1];
	}
	return (ret);
}
