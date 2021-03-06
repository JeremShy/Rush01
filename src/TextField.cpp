#include "TextField.hpp"
#include "display.hpp"
#include <iostream>
#include <fstream>

//PUBLIC
TextField::TextField() {}

TextField::TextField(std::string text, unsigned int size) : _text(text), _size(size) {
	// std::cout << "Creating a TextField with text: " << _text << std::endl;
}

TextField::~TextField() {
	std::cout << "Destroying a TextField !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
}

std::string				TextField::getText(void) const {
	return this->_text;
}

unsigned int			TextField::getSize(void) const {
	return this->_size;
}

void							TextField::setText(std::string const text) {
	this->_text = text;
}

void							TextField::setSize(unsigned int const size) {
	this->_size = size;
}

TextField::TextField(TextField const & textfield) {
	this->_text = textfield._text;
	this->_size = textfield._size;
}

std::vector<int>	TextField::getFieldSizeForNcurse(void) const
{
	// std::cout << "In TextField::getFieldSizeForNcurse" << std::endl;
	std::vector<int> vec(2,0);

	// std::cout << "Trying to get field size : field : " << this->_text << std::endl;
	vec[1] = ((this->_text).length()) / 30;
	// std::cout << "ici" << std::endl;
	if (vec[1] > 0) {
		vec[0] = 30;
	}
	else {
		vec[0] = this->_text.length();
	}
	// std::cout << "Returning from getFieldSizeForNcurse" << std::endl;
	return (vec);
}

std::vector<int>	TextField::printFieldForNcurse(int x, int y) const
{
	std::vector<int> vec = this->getFieldSizeForNcurse();

	int curx = x;
	int cury = y;

	std::fstream a("log.log", std::fstream::out | std::fstream::app);
	a << "------------------------------------------------------------trying to print " << _text << std::endl;
	for (std::string::const_iterator i = _text.begin(); i != _text.end(); ++i)
	{
		a << "writing : [" << *i << "] at " << curx << "-" << cury << std::endl;
		printCharAt(curx, cury, *i);
		curx++;
		if (curx >= x + 30) {
			curx = x;
			cury++;
		}
	}
	vec[0] = curx;
	vec[1] = cury;
	return (vec);
}

//PRIVATE

TextField & TextField::operator=(TextField const & textfield) {
	this->_text = textfield.getText();
	this->_size = textfield.getSize();
	return *this;
}
