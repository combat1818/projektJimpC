#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>



typedef struct
{
    int w;
    int h;
    int **points;
} * board_t;

board_t createBoard(int, int);

board_t fillBoard(FILE *);

void printBoard(board_t);

board_t setNewBoard(board_t, int);
#endif
