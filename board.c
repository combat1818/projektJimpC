#include "board.h"
#include <stdlib.h>

board_t createBoard(int w, int h)
{
    board_t board = malloc(sizeof(board_t));
    board->points = calloc(h, sizeof(int *));
    for (int i = 0; i < h; i++)
    {
        board->points[i] = calloc(w, sizeof(int *));
    }
    board->w = w;
    board->h = h;
    return board;
}

board_t fillBoard(FILE *f)
{
    int w, h;
    if (fscanf(f, "%d%d", &w, &h) != 2)
        exit(0);
    if(w<=0 || h<=0)
        return NULL;
    board_t p = createBoard(w, h);
    p->w = w;
    p->h = h;
    int new;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (fscanf(f, "%d", &new) == 1)
            {
                if (new >= 0 && new <= 255)
                {
                    p->points[i][j] = new;
                }else{
                    return NULL;
                }
            }
        }
    }
    return p;
}