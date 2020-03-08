#include "board.h"
#include <stdlib.h>

board_t createBoard(int w, int h)
{
    board_t board;
    board.points = calloc(h, sizeof(int *));
    for (int i = 0; i < h; i++)
    {
        board.points[i] = calloc(w, sizeof(int *));
    }
    board.w = w;
    board.h = h;
    return board;
}
