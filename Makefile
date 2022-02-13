ARG = 3

# Compile
compile: main.c img.c shape.c action.c
	gcc -lm main.c img.c shape.c action.c

test: test.c img.c shape.c action.c
	gcc -lm test.c img.c shape.c action.c; rm -rf images/*.ppm

gif_mac:
	magick -delay ${ARG} images/*.ppm images/animated.gif

gif: images/*.ppm
	animate images/img*.ppm

convert: images/*.ppm
	convert -delay ${ARG} images/img*.ppm out.gif

chmod:
	chmod 600 *.h *.c Makefile

