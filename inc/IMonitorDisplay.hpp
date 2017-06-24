#ifndef IMONITORDISPLAY_CLASS_H
# define IMONITORDISPLAY_CLASS_H

#include <DisplayBlock.hpp>
#include <vector>

class IMonitorDisplay {
public:
	virtual void							display(std::vector<DisplayBlock>) const = 0;
	virtual std::vector<int>	printDisplayBlock(DisplayBlock block, int x, int y) const = 0;
	virtual std::vector<int>	getDisplayBlockSize(DisplayBlock block) const = 0;
};
#endif
