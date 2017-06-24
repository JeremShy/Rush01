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

	long	getDiffAsMillis(void) const;
	long	getDiffAsMicros(void) const;

	static long	get_millis_time(void);
	static long	get_micros_time(void);
private:
	long	_time;
};

#endif
