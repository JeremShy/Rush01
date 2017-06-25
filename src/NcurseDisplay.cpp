#include <NcurseDisplay.hpp>
#include <display.hpp>
#include <fstream>

NcurseDisplay::NcurseDisplay(void) {
	init_ncurse();
}

NcurseDisplay::NcurseDisplay(NcurseDisplay const & src) {
}

NcurseDisplay::~NcurseDisplay(void) {
}

NcurseDisplay & NcurseDisplay::operator=(NcurseDisplay const & rhs) {
	return (*this);
}

void							NcurseDisplay::display(std::deque<DisplayBlock> list) const{
	int xmax = get_size_x();
	int ymax = get_size_y();
	int	xcol = 0;
	int	x = 0;
	int	y = 0;
	std::vector<int> vec(2,0);

	std::deque<DisplayBlock>::iterator iterator;
	std::fstream a("log.log", std::fstream::out | std::fstream::app);
	for (iterator = list.begin(); iterator != list.end() ; ++iterator)
	{
		// std::cout << "iterating in first for " << std::endl;
		vec = getDisplayBlockSize(*iterator);
		if (vec[0] > xcol) {
			xcol = vec[0];
		}
		if (y + vec[1] > ymax)
		{
			x += 30 + 2;
			y = 0;
			xcol = 0;
		}
		this->printDisplayBlock(*iterator, x, y);
		a << "vec[0] : " << vec[0] << " - vec[1] : " << vec[1] << std::endl;
		// x += vec[0];
		y += vec[1];
		a << "x : " << x << " - y : " << y << std::endl;
	}
	a.close();
}

std::vector<int>	NcurseDisplay::getDisplayBlockSize(DisplayBlock const & block) const  {
	// std::cout << "//////////////////////////////////////////////////" << std::endl;
	std::vector<int> ret(2, 0);
	std::vector<int> vec(2, 0);
	int	x = 0;
	int	y = 0;

	std::deque<AField*>fields = block.getFields();
	// std::deque<AField*>::iterator end = block.getFields().end();
	// std::cout << "Block : " << &block << std::endl;
	std::fstream a("log.log", std::fstream::out | std::fstream::app);
	for (std::deque<AField*>::iterator  iterator = fields.begin(); iterator != fields.end() ; ++iterator)
	{
		// std::cout << "Begin : " << *iterator << std::endl;
		// std::cout << "Iterating in getDisplayBlockSize" << std::endl;
		vec = (*iterator)->getFieldSizeForNcurse();
		// std::cout << "Successfully Returned from getFieldSizeForNcurse" << std::endl;
		a << "vec[0] : " << vec[0] << std::endl;
		a << "vec[1] : " << vec[1] << std::endl;
		y += vec[1] + 1;
		if (vec[0] > x)
			x = vec[0];
		// std::cout << "End of for of getDisplayBlockSize" << std::endl;
	}
	ret[0] = x;
	ret[1] = y + 1;
	// std::cout << "Returning from getDisplayBlockSize" << std::endl;
	// std::cout << "//////////////////////////////////////////////////" << std::endl;
	a.close();
	return (ret);
}

std::vector<int>	NcurseDisplay::printDisplayBlock(DisplayBlock const & block, int x, int y)const  {
	std::vector<int> ret(2, 0);
	std::vector<int> vec(2, 0);

	std::deque<AField*>::iterator iterator;
	std::deque<AField*>::iterator end = (block.getFields()).end();

	std::fstream a("log.log", std::fstream::out | std::fstream::app);
	a << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Entering in DisplayBlock" << std::endl;
	// std::cout << "Block : " << &block << std::endl;
	int curx = x;
	int cury = y;
	std::deque<AField*>fields = block.getFields();
	for (std::deque<AField*>::iterator  iterator = fields.begin(); iterator != fields.end() ; ++iterator)
	{
		// std::cout << "Starting DisplayBlockFor" << std::endl;
		// std::cout << "iterator : " << *iterator << std::endl;
		a << "Writing at : " << curx << " - " << cury << std::endl;
		vec = (*iterator)->printFieldForNcurse(curx, cury);
		// vec = (*iterator)->getFieldSizeForNcurse();
		cury = vec[1] + 1;
		// std::cout << "Ending DisplayBlockFor" << std::endl;
	}
	a.close();
	ret[0] = curx;
	ret[1] = cury;
	// std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Leaving DisplayBlock" << std::endl;
	return (ret);
}
