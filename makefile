prog:fonction.o main.o backg.o
	gcc fonction.o main.o backg.o -o prog -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer

main.o:main.c 
	gcc -c main.c 
fonction.o:fonction.c 
	gcc -c fonction.c 
backg.o:backg.c
	gcc -c backg.c

