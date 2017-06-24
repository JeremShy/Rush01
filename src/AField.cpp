#include "AField.hpp"
#include <iostream>

AField::AField() {

}

AField::AField(AField const & afield) {

}

AField::~AField() {
	std::cout << "Destructing an AFIeld." <<std::endl;
}

AField & AField::operator=(AField const & afield) {
	return *this;
}
