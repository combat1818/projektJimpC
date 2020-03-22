run: main.o pngCreator.o board.o
	$(CC) -o a.out main.o pngCreator.o board.o -lpng -lz
generate: generuj.o 
		$(CC) -o gen.out generuj.o