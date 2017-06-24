#include "TextField.hpp"


//PUBLIC
TextField::TextField() {}

TextField::TextField(std::string text, unsigned int size) : _text(text), _size(size) {
}

TextField::~TextField() {}

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

//PRIVATE
TextField::TextField(TextField const & textfield) {
	this->_text = textfield._text;
	this->_size = textfield._size;
}

TextField & TextField::operator=(TextField const & textfield) {
	this->_text = textfield.getText();
	this->_size = textfield.getSize();
	return *this;
}
