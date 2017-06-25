#include "HistogramField.hpp"


//PUBLIC
HistogramField::HistogramField() {}
HistogramField::~HistogramField() {}
HistogramField::THistory 		HistogramField::getHistory() const
{
	return this->_history;
}
int													HistogramField::getMaxValue() const
{
	return this->_max_value;
}

void												HistogramField::push_back(int	value)
{
	std::pair<int, time_t>	entry;

	entry.first = value;
	entry.second = time(NULL);
	this->_history.push_back(entry);
	if (value > this->_max_value)
		this->_max_value = value;
}

void														HistogramField::remove_old()
{
	while (difftime(time(NULL), (this->_history.begin())->second) > 3600 && this->_history.size())
		this->_history.pop_front();
}

void													HistogramField::show()
{
	THistory::iterator it = this->_history.begin();
	THistory::iterator next = it;
	while (++next != this->_history.end())
		std::cout << it->first << " - " << next->second - (it++)->second << std::endl;
	std::cout << "current : " << it->first << std::endl;
	std::cout << "max : " << this->_max_value << std::endl;
	std::cout << "time span : " << this->_history.rbegin()->second - this->_history.begin()->second << std::endl;
}


std::vector<int>								HistogramField::getFieldSizeForNcurse(void) const
{
		std::vector<int> null;
		return null;// TODO
}

std::vector<int> 								HistogramField::printFieldForNcurse(int x, int y) const
{
		std::vector<int> null;
		return null;// TODO
}
//PRIVATE

HistogramField::HistogramField(HistogramField const & histogramfield) {
	this->_history = histogramfield._history;
	this->_max_value = histogramfield._max_value;
}
HistogramField & HistogramField::operator=(HistogramField const & histogramfield) {
	this->_history = histogramfield.getHistory();
	this->_max_value = histogramfield.getMaxValue();

	return *this;
}
