#include "SDLDisplay.hpp"
#include "display.hpp"
#include <fstream>

SDLDisplay::SDLDisplay(void) : _e(SDL_Event()), _window(NULL), _screenSurface(NULL),
	_textSurface(NULL), _blockSurfaces(std::deque<SDL_Surface*>()), _font(NULL)
{

	if (SDL_Init(SDL_INIT_VIDEO) < 0 ||
			!(this->_screenSurface = SDL_GetWindowSurface( this->_window )) ||
			TTF_Init() < 0)
		throw std::exception();
	  atexit(SDL_Quit);
}

SDLDisplay::SDLDisplay(SDLDisplay const & src) {
}

SDLDisplay::~SDLDisplay(void) {
	SDL_FreeSurface(this->_screenSurface);
	SDL_FreeSurface(this->_textSurface);
	SDL_DestroyWindow(this->_window);
	TTF_CloseFont(this->_font);
	TTF_Quit();
	SDL_Quit();
}

SDLDisplay & SDLDisplay::operator=(SDLDisplay const & rhs) {
	return (*this);
}

SDL_Surface				*SDLDisplay::renderBlock(DisplayBlock *block)
{
	int			block_height = 0;
	std::deque<SDL_Surface*>	fieldSurfaces;
	SDL_Surface*							blockSurface;
	for(std::deque<Afield*>::iterator field = block->begin(); field != block->end(); ++field)
	{
		fieldSurfaces.push_front(render(field));
		block_height+=fieldSurfaces.begin()->h;
	}
	SDL_Renderer* renderer,
    SDL_Rect rectangle
}

void							SDLDisplay::display(std::deque<DisplayBlock> list) const
{
	int			window_height = 0;

	for(std::deque<DisplayBlock>::iterator it = list.begin(); it != list.end(); ++it )
	{
		this->_blockSurfaces.push_front(render(it));
		window_height += this->_blockSurfaces.begin()->h;
	}
	if (!(this->_window || (this->_window = SDL_CreateWindow(
					"GKrellM",
					SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
					400, window_height,
					SDL_WINDOW_SHOWN))))
		throw std::exception();
	if (this->_window->h != window_height)
		SDL_SetWindowSize(window, 400, window_height)


}
