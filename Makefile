program=ppmplayer
flags=-Wall -std=c99
src=$(shell find src -name "*.c")
obj=$(src:.c=.o)
CFLAGS=`sdl2-config --cflags`
SDLLIBS=`sdl2-config --libs`


all: $(program)

debug: setdebug $(program)

$(program): $(obj)
	gcc -o $@ $^ 

%.o: %.c %.h
	gcc -c $< -o $@ $(flags) $(CFLAGS) $(SDLLIBS)

%.o: %.c
	gcc -c $< -o $@ $(flags) $(CFLAGS) $(SDLLIBS)

clean:
	@find src/ -type f -name '*.o' -delete

setdebug:
	$(eval flags := $(flags) -g)


	# gcc -I/usr/local/include/SDL2 -o hello hello-pixel.c -lSDL2
