#include <stdio.h>

typedef struct
{
    int w;
    int h;
    int **points;
} *board_t;

board_t createBoard(int, int);

board_t fillBoard(FILE *);
