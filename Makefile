program=ppmplayer
flags=-Wall -std=c99 
src=$(shell find src -name "*.c")
obj=$(src:.c=.o)
CFLAGS=`sdl2-config --cflags`
LFLAGS=`sdl2-config --libs` -lm


all: $(program)

debug: setdebug $(program)

$(program): $(obj)
	gcc -o $@ $^ $(LFLAGS)

%.o: %.c %.h
	gcc -c $< -o $@ $(flags) $(CFLAGS) 

%.o: %.c
	gcc -c $< -o $@ $(flags) $(CFLAGS) 

clean:
	@find src/ -type f -name '*.o' -delete

setdebug:
	$(eval flags := $(flags) -g)


	# gcc -I/usr/local/include/SDL2 -o hello hello-pixel.c -lSDL2
