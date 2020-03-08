a.out: main.o pngCreator.o
	$(CC) -o a.out main.o pngCreator.o -lpng -lz