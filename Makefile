ARG = 3

# Compile
compile: main.c img.c shape.c
	gcc -lm main.c img.c shape.c

gif_mac: images/*.ppm
	magick -delay ${ARG} images/*.ppm images/animated.gif

gif: images/*.ppm
	animate images/img*.ppm

convert: images/*.ppm
	convert -delay ${ARG} images/img*.ppm out.gif

