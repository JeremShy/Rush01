#include "DisplayBlock.hpp"

//PUBLIC
DisplayBlock::DisplayBlock(void) {

}


DisplayBlock::~DisplayBlock(void) {
	this->_fields.clear();
	std::cout << "Here" << std::endl;
}


void										DisplayBlock::addField(AField *field)
{
	this->_fields.push_back(field);
}

std::vector<AField*>				DisplayBlock::getFields(void) const
{
	return this->_fields;
}

//PRIVATE

DisplayBlock::DisplayBlock(DisplayBlock const & src) : _fields(src.getFields())
{
}

DisplayBlock & DisplayBlock::operator=(DisplayBlock const & rhs) {
	this->_fields = rhs._fields;

	// this->_fields = new std:vector<AField>;
	// for(std::vector<AField>::const_iterator it = rhs->_fields.begin(); it != rhs->_fields.end(); ++it )
	// this->_fields.addField(*it);
	return (*this);
}
