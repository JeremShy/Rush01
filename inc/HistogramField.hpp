#ifndef HISTOGRAMFIELD_HPP
# define HISTOGRAMFIELD_HPP


# include <deque>
# include <utility>
# include <vector>
# include <AField.hpp>
# include <ctime>
# include <iostream>//////////////////for testing
class HistogramField : public AField
{
public:
	typedef std::deque<std::pair <int, time_t> > THistory;
	HistogramField();
	~HistogramField();
	THistory					getHistory() const;
	int							getMaxValue() const;
	void							push_back(int	value);
	void							remove_old();
	void							show();
	std::vector<int>	getFieldSizeForNcurse(void) const;
	std::vector<int> 	printFieldForNcurse(int x, int y) const;
private:
	HistogramField(HistogramField const & histogramfield);
	HistogramField			& operator=(HistogramField const & histogramfield);
	THistory							_history;
	int										_max_value;
};

# endif
