#include <Timer.hpp>
#include <sys/time.h>

Timer::Timer(void) : _time(0){
}

Timer::Timer(Timer const & src) : _time(src._time){
}

Timer::~Timer(void) {
}

Timer & Timer::operator=(Timer const & rhs) {
	this->_time = rhs._time;

	return (*this);
}

void	Timer::start(void) {
	this->_time = Timer::get_micros_time();
}
void	Timer::restart(void) {
	this->_time = Timer::get_micros_time();
}
void	Timer::stop(void) {
	this->_time = 0;
}

unsigned long	Timer::getDiffAsMillis(void) const {
	return (Timer::get_millis_time() - (this->_time / 1000));
}

unsigned long	Timer::getDiffAsMicros(void) const {
	return (Timer::get_micros_time() - this->_time);
}

unsigned long	Timer::get_millis_time(void) {
	timeval tim;
	gettimeofday(&tim, NULL);
	return (tim.tv_sec * 1000 + tim.tv_usec / 1000);
}

unsigned long	Timer::get_micros_time(void) const{
	timeval tim;
	gettimeofday(&tim, NULL);
	return (tim.tv_sec * 1000000 + tim.tv_usec);
}
