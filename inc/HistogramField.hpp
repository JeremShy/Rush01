#ifndef HISTOGRAMFIELD_HPP
# define HISTOGRAMFIELD_HPP

#include <list>

class HistogramField : public Afield {
public:
	HistogramField();
	~HistogramField();
private:
	HistogramField(HistogramField const & histogramfield);
	HistogramField			& operator=(HistogramField const & histogramfield);
	std::list<int>				_history;
	int										_max_value;
};

# endif
