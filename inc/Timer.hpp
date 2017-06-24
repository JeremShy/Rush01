#ifndef TIMER_CLASS_H
# define TIMER_CLASS_H

# include <string>
# include <iostream>

class Timer {
public:
	Timer(void);
	Timer(Timer const & src);
	~Timer(void);

	Timer & operator=(Timer const & rhs);

	void	start(void);
	void	restart(void);
	void	stop(void);

	unsigned long	getDiffAsMillis(void) const;
	unsigned long	getDiffAsMicros(void) const;

	static unsigned long	get_millis_time(void);
	unsigned long	get_micros_time(void) const;
private:
	unsigned long	_time;
};

#endif
