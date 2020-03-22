a->out: main.o pngCreator.o board.o
	$(CC) -o a.out main.o pngCreator.o board.o -lpng -lz
