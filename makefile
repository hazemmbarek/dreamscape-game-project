prog:es.o main.o
	gcc es.o main.o -o prog -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer

main.o:main.c 
	gcc -c main.c 
es.o:es.c 
	gcc -c es.c
