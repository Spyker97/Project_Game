prog:scrolling.o main.o
	gcc scrolling.o main.o -o prog -lSDL -lSDL_image$
main.o:main.c
	gcc -c main.c
scrolling.o:scrolling.c
	gcc -c scrolling.c
