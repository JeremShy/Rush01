#ifndef IMONITORDISPLAY_CLASS_H
# define IMONITORDISPLAY_CLASS_H

#include <DisplayBlock.hpp>
#include <vector>

class IMonitorDisplay {
public:
	virtual void							display(std::deque<DisplayBlock>) const = 0;
	virtual std::vector<int>	printDisplayBlock(DisplayBlock const & block, int x, int y) const = 0;
	virtual std::vector<int>	getDisplayBlockSize(DisplayBlock const & block) const = 0;
};
#endif
