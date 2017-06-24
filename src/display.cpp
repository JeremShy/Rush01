#include "display.hpp"
#include <sys/ioctl.h>
#include <iostream>
#include <sstream>

void	printCharAt(int x, int y, char c) {
	mvaddch(y, x, c);
}

void	init_ncurse(void) {
	initscr();
	noecho();
	cbreak();
	curs_set(0);
	keypad(stdscr, TRUE);
}

void	close_ncurse(void) {
	endwin();
}

int	get_size_x(void) {
	struct winsize size;
	if (ioctl(0, TIOCGWINSZ, (char *) &size) < 0)
	{
		close_ncurse();
		std::cout << "error with ioctl" << std::endl;
		exit(EXIT_FAILURE);
	}
	return size.ws_col;
}

int	get_size_y(void) {
	struct winsize size;
	if (ioctl(0, TIOCGWINSZ, (char *) &size) < 0)
	{
		close_ncurse();
		std::cout << "error with ioctl" << std::endl;
		exit(EXIT_FAILURE);
	}
	return (size.ws_row - 5);
}
