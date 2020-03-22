#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
	srand(time(NULL));
	FILE *plik = fopen(argv[1], "w");
	if (argc < 3)
	{
		printf("podaj nazwe pliku i rozmiar macierzy\n");
		return 0;
	}
	if (plik == NULL)
	{
		printf("Podaj plik\n");
		return 0;
	}
	int h = atoi(argv[2]);
	int w = atoi(argv[3]);
	int x;
	fprintf(plik, "%d %d\n", h, w);
	int i, j;
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			x = rand() % 2;
			fprintf(plik, "%d ", x ? 255 : 0);
		}
		fprintf(plik, "\n");
	}
	return 0;
}
