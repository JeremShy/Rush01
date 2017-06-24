#include "HistogramField.hpp"


//PUBLIC
HistogramField::HistogramField() {}
HistogramField::HistogramField(HistogramField const & histogramfield) {
	this->_history = histogramfield._history;
	this->_max_value = histogramfield._max_value;
}
HistogramField::~HistogramField() {}
HistogramField & HistogramField::operator=(HistogramField const & histogramfield) {
	this->_history = histogramfield.getHistory;
	this->_max_value = histogramfield.getMaxValue;

	return *this;
}
//private
