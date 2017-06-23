#include <main.hpp>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
# define GIF (const char*[15]) { "assets/poney/1.bmp", "assets/poney/2.bmp",\
							"assets/poney/3.bmp", "assets/poney/4.bmp", "assets/poney/5.bmp",\
							"assets/poney/6.bmp", "assets/poney/7.bmp", "assets/poney/8.bmp",\
							"assets/poney/9.bmp", "assets/poney/10.bmp", "assets/poney/11.bmp",\
							"assets/poney/12.bmp", "assets/poney/13.bmp", "assets/poney/14.bmp",\
							"assets/poney/15.bmp"}

bool init(SDL_Window** window, SDL_Surface** screenSurface)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Could not initialize SDL2 !\n"
							<< SDL_GetError() << std::endl;
		return false;
	}
  atexit(SDL_Quit);
	if (!(*window = SDL_CreateWindow(
					"GKrellM",
					SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
					SCREEN_WIDTH, SCREEN_HEIGHT,
					SDL_WINDOW_SHOWN))) {
	    std::cout << "Could not create window: !\n"
			 					<< SDL_GetError() << std::endl;
	    return false;
		}
	*screenSurface = SDL_GetWindowSurface( *window );
	return true;
}

void close(SDL_Window* window, SDL_Surface* screenSurface)
{
	SDL_FreeSurface(screenSurface);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void	aminate(SDL_Window* window, SDL_Surface* screenSurface){
	SDL_Rect screenrect;
	SDL_Surface* image = NULL;
	screenrect.x = (SCREEN_WIDTH - 245) / 2;
	screenrect.y = (SCREEN_HEIGHT - 140) / 2;
	screenrect.w = 245;
	screenrect.h = 140;
	for (int i = 0; i < 15; i++) {
		if (!(image = SDL_LoadBMP( GIF[i] ))){
			std::cout << "Could not load image: !\n" << SDL_GetError() << std::endl;
			return;
		}
		SDL_BlitSurface( image, NULL, screenSurface, &screenrect);
	  SDL_UpdateWindowSurface(window);
		SDL_Delay( 100 );
	}
	SDL_FreeSurface( image );
}


int main() {
	bool quit = false;
	SDL_Event e;
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	if( !init(&window, &screenSurface) ) {
		return -1; }
  SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x55, 0xFF, 0xFF));
	SDL_UpdateWindowSurface(window);
	SDL_Delay( 1000 );
	// SDL_Delay( 1000 );
	while( !quit ) {
		aminate(window, screenSurface);
		while( SDL_PollEvent( &e ) != 0 ) {
			//User requests quit
			if( e.type == SDL_QUIT ) {
				quit = true;
			}
		}
	}
	close(window, screenSurface);
  return 0;
}
