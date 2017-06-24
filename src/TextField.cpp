#include "TextField.hpp"


//PUBLIC
TextField::TextField() {}
TextField::TextField(std::string text, unsigned int size) : _text(text), _size(size)
{

}
TextField::~TextField() {}
std::string				getText(void) const
{
	return this->_text;
}
unsigned int			getSize(void) const
{
	return this->_size;
}
void							setText(std::string const text)
{
	this->_text = text;
}
void							setSize(unsigned int const size)
{
	this->_size = size;
}
//PRIVATE
TextField::TextField(TextField const & textfield) {
	this->_text = textfield._text;
	this->-size = textfield._size;
}
TextField & TextField::operator=(TextField const & textfield) {
	this->_text = textfield.getText();
	this->-size = textfield.getSize();
	return *this;
}
