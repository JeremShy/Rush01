#ifndef SDL_DISPLAY_CLASS_H
# define SDL_DISPLAY_CLASS_H

# include <string>
# include <iostream>
# include <IMonitorDisplay.hpp>
# include <SDL2/SDL.h>
# include <SDL_ttf.h>
# include <deque>

class SDLDisplay : IMonitorDisplay{
public:
	SDLDisplay(void);
	SDLDisplay(SDLDisplay const & src);
	~SDLDisplay(void);



	SDLDisplay & operator=(SDLDisplay const & rhs);


	void							display(std::deque<DisplayBlock> blocks) const;
	// std::vector<int>	printDisplayBlock(DisplayBlock const & block, int x, int y) const;
	// std::vector<int>	printField(AField *field, int x, int y) const;
	// std::vector<int>	getDisplayBlockSize(DisplayBlock const & block) const;

private:
	SDL_Event									_e;
	SDL_Window*								_window;
	SDL_Surface*							_screenSurface;
	SDL_Surface*							_textSurface;
	std::deque<SDL_Surface*>	_blockSurfaces;
	TTF_Font* _font;
};
#endif
