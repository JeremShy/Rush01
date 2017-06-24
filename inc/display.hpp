#ifndef DISPLAY_H
#define DISPLAY_H

#include <ncurses.h>

void	printCharAt(int x, int y, char c);
void	init_ncurse(void);
void	close_ncurse(void);
int		get_size_x(void);
int		get_size_y(void);

#endif
