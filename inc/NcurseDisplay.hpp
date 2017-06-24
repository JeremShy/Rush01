#ifndef NCURSE_DISPLAY_CLASS_H
# define NCURSE_DISPLAY_CLASS_H

# include <string>
# include <iostream>
# include <IMonitorDisplay.hpp>

class NcurseDisplay : IMonitorDisplay{
public:
	NcurseDisplay(void);
	NcurseDisplay(NcurseDisplay const & src);
	~NcurseDisplay(void);

	NcurseDisplay & operator=(NcurseDisplay const & rhs);

	void							display(std::vector<DisplayBlock>) const;
	std::vector<int>	printDisplayBlock(DisplayBlock block, int x, int y) const;
	std::vector<int>	printField(AField *field, int x, int y) const;
	std::vector<int>	getDisplayBlockSize(DisplayBlock block) const;

private:
};
#endif
