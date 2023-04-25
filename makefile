prog:minimap.o main.o
	gcc minimap.o main.o -o prog -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer

main.o:main.c 
	gcc -c main.c 
fonction.o:fonction.c 
	gcc -c minimap.c
