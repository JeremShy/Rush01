#include <TimeModule.hpp>
#include <TextField.hpp>
#include <ctime>
#include <sstream>
#include <iomanip>

TimeModule::TimeModule(void) {

}

TimeModule::TimeModule(TimeModule const & src) {

}

TimeModule::~TimeModule(void) {

}

TimeModule & TimeModule::operator=(TimeModule const & rhs) {
	return (*this);
}

DisplayBlock TimeModule::getDisplayInfo(void) {
	time_t t = time(NULL);

	struct tm *now = localtime(&t);
	std::string date;
	std::string heure;

	std::stringstream sdate;
	std::stringstream sheure;

	sdate << (now->tm_year + 1900) << ":" << std::setw(2) << std::setfill('0') << (now->tm_mon + 1) << ":" << now->tm_mday;
	sheure << std::setw(2) << std::setfill('0') << now->tm_hour << ":" << std::setw(2) << std::setfill('0') << now->tm_min << ":" << std::setw(2) << std::setfill('0') << now->tm_sec;

	date = sdate.str();
	heure = sheure.str();

	DisplayBlock ret;
	ret.addField(new TextField("Date: " + date, 25));
	ret.addField(new TextField("Heure: " + heure, 25));

	// std::cout << "date: " << date << std::endl << "heure: " << heure << std::endl;
	return (ret);
}
