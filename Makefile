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
								 Timer \
								 MemModule \
								 NcurseDisplay \
								 display
SRC						= $(addprefix src/, $(addsuffix .cpp, $(FILES)))
OBJ						= $(addprefix obj/, $(addsuffix .o, $(FILES)))
SDL_DIR				= SDL
LIBS_DIR			= $(SDL_DIR)/lib
PATH_SDL			= SDL2-2.0.5
PATH_SDL_IMG	= SDL2_image-2.0.1
PATH_FREETYPE	= freetype-2.8
PATH_SDL_TTF	= SDL2_ttf-2.0.14
CMP						=	clang++
INC =  -I inc -I $(SDL_DIR)/include -I $(SDL_DIR)/include/SDL2 -I $(LIBS_DIR)
SDL		=	`./$(SDL_DIR)/bin/sdl2-config --cflags --libs` -lSDL2_image -lSDL2_ttf -lncurses

all: sdl_components $(NAME)

sdl_components: $(SDL_DIR) $(LIBS_DIR)/libSDL2.a $(LIBS_DIR)/libSDL2_image.a $(LIBS_DIR)/libfreetype.a $(LIBS_DIR)/libSDL2_ttf.a

$(SDL_DIR):
	@mkdir -p $(SDL_DIR)

$(LIBS_DIR)/libSDL2.a:
	@echo "\033[32mDownloading $(PATH_SDL) ...\033[0m"
	@curl https://www.libsdl.org/release/SDL2-2.0.5.tar.gz -o $(PATH_SDL).tar.gz
	@echo "\033[32mExtracting $(PATH_SDL) ...\033[0m"
	@tar -xf $(PATH_SDL).tar.gz
	@rm -rf $(PATH_SDL).tar.gz
	@echo "\033[32mCompiling $(PATH_SDL) ...\033[0m"
	@cd $(PATH_SDL) && ./configure --prefix=`cd ../$(SDL_DIR) && pwd` && make -j 8 -s  && make -j 8 -s install
	@rm -rf $(PATH_SDL)

$(LIBS_DIR)/libSDL2_image.a:
	@echo "\033[32mDownloading $(PATH_SDL_IMG) ...\033[0m"
	@curl https://www.libsdl.org/projects/SDL_image/release/SDL2_image-2.0.1.tar.gz -o $(PATH_SDL_IMG).tar.gz
	@echo "\033[32mExtracting $(PATH_SDL_IMG) ...\033[0m"
	@tar -xf $(PATH_SDL_IMG).tar.gz
	@rm -rf $(PATH_SDL_IMG).tar.gz
	@echo "\033[32mCompiling $(PATH_SDL_IMG) ...\033[0m"
	@cd $(PATH_SDL_IMG) && ./configure --prefix=`cd ../$(SDL_DIR) && pwd` && make -j 8 -s && make -j 8 -s install
	@rm -rf $(PATH_SDL_IMG)

 $(LIBS_DIR)/libfreetype.a:
	@echo "\033[32mDownloading $(PATH_FREETYPE) ...\033[0m"
	@curl --remote-name --location http://download.savannah.gnu.org/releases/freetype/freetype-2.8.tar.gz -o $(PATH_FREETYPE).tar.gz
	@echo "\033[32mExtracting $(PATH_FREETYPE) ...\033[0m"
	@tar -xf $(PATH_FREETYPE).tar.gz
	@rm -rf $(PATH_FREETYPE).tar.gz
	@echo "\033[32mCompiling $(PATH_FREETYPE) ...\033[0m"
	@cd $(PATH_FREETYPE) && ./configure --prefix=`cd ../$(SDL_DIR) && pwd` && make -j 8 -s && make -j 8 -s install
	@rm -rf $(PATH_FREETYPE)

 $(LIBS_DIR)/libSDL2_ttf.a:
	@echo "\033[32mDownloading $(PATH_SDL_TTF) ...\033[0m"
	@curl https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.14.tar.gz -o $(PATH_SDL_TTF).tar.gz
	@echo "\033[32mExtracting $(PATH_TTF) ...\033[0m"
	@tar -xf $(PATH_SDL_TTF).tar.gz
	@rm -rf $(PATH_SDL_TTF).tar.gz
	@echo "\033[32mCompiling $(PATH_TTF) ...\033[0m"
	@cd $(PATH_SDL_TTF) && ./configure --with-freetype-prefix=`cd ../$(SDL_DIR) && pwd` --prefix=`cd ../$(SDL_DIR) && pwd` --with-sdl-prefix=`cd ../$(SDL_DIR) && pwd` && make -j 8 && make -j 8 install
	@rm -rf $(PATH_SDL_TTF)

$(NAME): obj $(OBJ)
	@echo "\033[32mLinking...\033[0m"
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
	@rm -rf $(SDL_DIR)
	@echo "\033[33;33m$(SDL_DIR) deleted\033[33;37m"

re: fclean all

rr: eclean all
	@./$(NAME)
