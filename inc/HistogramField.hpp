#ifndef HISTOGRAMFIELD_HPP
# define HISTOGRAMFIELD_HPP

#include <list>

class HistogramField : public AField {
public:
	HistogramField();
	~HistogramField();
	std::vector<int>	getFieldSizeForNcurse(void);

private:
	HistogramField(HistogramField const & histogramfield);
	HistogramField			& operator=(HistogramField const & histogramfield);
	std::list<int>				_history;
	int										_max_value;
};

# endif
