.PHONY: all, clean, fclean, re

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif
NAME					=	GKrellM
FILES					= main \
								 HostnameModule \
								 DisplayBlock \
								 OsInfoModule \
								 TimeModule \
								 AField \
								 TextField \
								 CPUModule \
								 Timer
SRC						= $(addprefix src/, $(addsuffix .cpp, $(FILES)))
OBJ						= $(addprefix obj/, $(addsuffix .o, $(FILES)))
LIB_SDL				= SDL
PATH_SDL			= SDL2-2.0.5
PATH_SDL_IMG	= SDL2_image-2.0.1
CMP						=	clang++
INC =  -I inc -I $(LIB_SDL)/include -I $(LIB_SDL)/lib/
SDL		=	`./$(LIB_SDL)/bin/sdl2-config --cflags --libs` -lSDL2_image

all: $(LIB_SDL) $(NAME)

$(LIB_SDL):
	@echo "\033[32mDownloading SDL ...\033[0m"
	@curl https://www.libsdl.org/release/SDL2-2.0.5.tar.gz -o $(PATH_SDL).tar.gz
	@curl https://www.libsdl.org/projects/SDL_image/release/SDL2_image-2.0.1.tar.gz -o $(PATH_SDL_IMG).tar.gz
	@echo "\033[32mCompiling SDL ...\033[0m"
	@mkdir -p $(LIB_SDL)
	@tar -xf $(PATH_SDL).tar.gz
	@tar -xf $(PATH_SDL_IMG).tar.gz
	@cd $(PATH_SDL) && ./configure --prefix=`cd ../$(LIB_SDL) && pwd` && make -j 8 && make -j 8 install
	@cd $(PATH_SDL_IMG) && ./configure --prefix=`cd ../$(LIB_SDL) && pwd` && make -j 8 && make -j 8 install
	@rm -rf $(PATH_SDL)
	@rm -rf $(PATH_SDL_IMG)
	@rm -rf $(PATH_SDL_IMG).tar.gz
	@rm -rf $(PATH_SDL).tar.gz

player:
	@echo "\033[32mDownloading something ...\033[0m"
	@curl https://codeload.github.com/pockethook/player/zip/master -o player.zip
	@echo "\033[32mCompiling something ...\033[0m"
	@unzip player.zip
	@rm -rf player.zip


$(NAME): obj $(OBJ)
	@$(CMP) -o $(NAME) $(OBJ) $(SDL)
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
