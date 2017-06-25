.PHONY: all, clean, fclean, re, sdl

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif
NAME					=	GKrellM
FILES					= AField \
									CPUModule \
									DisplayBlock \
									HostnameModule \
									MemModule \
									NcurseDisplay \
									OsInfoModule \
									TextField \
									TimeModule \
									Timer \
									display \
									main
									# _test_histogramfield \
									# HistogramField \
									# SDLDisplay \
									# customSDL \

SRC						= $(addprefix src/, $(addsuffix .cpp, $(FILES)))
OBJ						= $(addprefix obj/, $(addsuffix .o, $(FILES)))
LIB_SDL				= SDL
PATH_SDL			= SDL2-2.0.5
PATH_SDL_IMG	= SDL2_image-2.0.1
PATH_FREETYPE	= freetype-2.8
PATH_SDL_TTF	= SDL2_ttf-2.0.14
CMP						=	clang++
INC =  -I inc -I $(LIB_SDL)/include -I $(LIB_SDL)/include/SDL2 -I $(LIB_SDL)/lib/ -I $(PATH_SDL_TTF) -g
SDL		=	`./$(LIB_SDL)/bin/sdl2-config --cflags --libs` -lSDL2_image -lncurses

all: sdl $(NAME)

sdl: $(LIB_SDL) $(PATH_SDL) $(PATH_SDL_IMG) $(PATH_FREETYPE) $(PATH_SDL_TTF)

$(LIB_SDL):
	@mkdir -p $(LIB_SDL)

$(PATH_SDL):
	@echo "\033[32mDownloading $(PATH_SDL) ...\033[0m"
	@curl https://www.libsdl.org/release/SDL2-2.0.5.tar.gz -o $(PATH_SDL).tar.gz
	@echo "\033[32mExtracting $(PATH_SDL) ...\033[0m"
	@tar -xf $(PATH_SDL).tar.gz
	@rm -rf $(PATH_SDL).tar.gz
	@echo "\033[32mCompiling $(PATH_SDL) ...\033[0m"
	@cd $(PATH_SDL) && ./configure --prefix=`cd ../$(LIB_SDL) && pwd` && make -j 8 -s  && make -j 8 -s install
	# @rm -rf $(PATH_SDL)

$(PATH_SDL_IMG):
	@echo "\033[32mDownloading $(PATH_SDL_IMG) ...\033[0m"
	@curl https://www.libsdl.org/projects/SDL_image/release/SDL2_image-2.0.1.tar.gz -o $(PATH_SDL_IMG).tar.gz
	@echo "\033[32mExtracting $(PATH_SDL_IMG) ...\033[0m"
	@tar -xf $(PATH_SDL_IMG).tar.gz
	@rm -rf $(PATH_SDL_IMG).tar.gz
	@echo "\033[32mCompiling $(PATH_SDL_IMG) ...\033[0m"
	@cd $(PATH_SDL_IMG) && ./configure --prefix=`cd ../$(LIB_SDL) && pwd` && make -j 8 -s && make -j 8 -s install
	# @rm -rf $(PATH_SDL_IMG)
$(PATH_FREETYPE):
	@echo "\033[32mDownloading $(PATH_FREETYPE) ...\033[0m"
	@curl --remote-name --location http://download.savannah.gnu.org/releases/freetype/freetype-2.8.tar.gz -o $(PATH_FREETYPE).tar.gz
	@echo "\033[32mExtracting $(PATH_FREETYPE) ...\033[0m"
	@tar -xf $(PATH_FREETYPE).tar.gz
	@rm -rf $(PATH_FREETYPE).tar.gz
	@echo "\033[32mCompiling $(PATH_FREETYPE) ...\033[0m"
	@mkdir -p $(PATH_FREETYPE)/freetype_lib
	@cd $(PATH_FREETYPE) && ./configure --prefix=`cd freetype_lib && pwd` && make -j 8 -s && make -j 8 -s install
	# @rm -rf $(PATH_FREETYPE)

$(PATH_SDL_TTF):
	@echo "\033[32mDownloading $(PATH_SDL_TTF) ...\033[0m"
	@curl https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.14.tar.gz -o $(PATH_SDL_TTF).tar.gz
	@echo "\033[32mExtracting $(PATH_TTF) ...\033[0m"
	@tar -xf $(PATH_SDL_TTF).tar.gz
	@rm -rf $(PATH_SDL_TTF).tar.gz
	@echo "\033[32mCompiling $(PATH_TTF) ...\033[0m"
	@cd $(PATH_SDL_TTF) && mkdir -p ttf_lib
# CFLAGS="-I `cd $(PATH_FREETYPE)/freetype_lib/include && pwd`" && LDFLAGS="-L`cd $(PATH_FREETYPE)/freetype_lib/lib && pwd`" && env &&

	export PKG_CONFIG_PATH="`cd $(PATH_FREETYPE)/builds/unix && pwd`" && env && cd $(PATH_SDL_TTF) && ./configure --with-freetype-prefix=`cd ../$(PATH_FREETYPE)/freetype_lib && pwd` --prefix=`cd ttf_lib && pwd` --with-sdl-prefix=`cd ../$(LIB_SDL) && pwd` && make -j 8 && make -j 8 install
	# @rm -rf $(PATH_SDL_TTF)

$(NAME): obj $(OBJ)
	@$(CMP) -o $(NAME) $(OBJ) $(SDL) -lSDL2_ttf -L SDL2_ttf-2.0.14/ttf_lib/lib
	@echo "\033[33;35m\t$(NAME) ready\033[33;37m"

obj:
	@mkdir -p obj

obj/%.o: src/%.cpp
	@$(CMP) -o $@ -c $< $(INC)
	@echo "\033[33;33m$@ compiled\033[33;37m"

clean:
	@rm -rf obj
	@echo "\033[33;33mAll objects deleted\033[33;37m"

eclean: clean
	@rm -f $(NAME)
	@echo "\033[33;33m$(NAME) deleted\033[33;37m"

fclean: eclean
	@rm -rf $(LIB_SDL)
	@echo "\033[33;33m$(LIB_SDL) deleted\033[33;37m"

re: fclean all

rr: eclean all
	@./$(NAME)
