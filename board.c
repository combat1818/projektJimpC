#include "board.h"
#include <stdlib.h>

#define L 0
#define D 255

board_t setNewBoard(board_t b, int gen)
{
    if (gen != 0)
    {
        board_t newBoard = createBoard(b->w, b->h);
        for (int i = 0; i < b->h; i++)
        {
            for (int j = 0; j < b->w; j++)
            {
                if (b->points[i][j] != 0)
                {
                    newBoard->points[i][j] = 255;
                }
                else
                {
                    newBoard->points[i][j] = b->points[i][j];
                }
            }
        }
        int counter = 0;
        for (int i = 0; i < b->h; i++)
        {
            for (int j = 0; j < b->w; j++)
            {
                if (i != 0 && j != 0 && j != b->w - 1 && i != b->h - 1)
                {
                    for (int z = i - 1; z < i + 2; z++)
                    {
                        for (int y = j - 1; y < j + 2; y++)
                        {
                            if (z == i && y == j)
                                continue;
                            else if (b->points[z][y] == L)
                                counter++;
                        }
                    }
                }
                else if (i == 0 && j == 0)
                {
                    if (b->points[0][1] == L)
                    {
                        counter++;
                    }
                    if (b->points[1][0] == L)
                    {
                        counter++;
                    }
                    if (b->points[1][1] == L)
                    {
                        counter++;
                    }
                }
                else if (i == 0 && j == b->w - 1)
                {
                    if (b->points[i][j - 1] == L)
                    {
                        counter++;
                    }
                    if (b->points[i + 1][j] == L)
                    {
                        counter++;
                    }
                    if (b->points[i + 1][j - 1] == L)
                    {
                        counter++;
                    }
                }
                else if (i == b->h - 1 && j == b->w - 1)
                {
                    if (b->points[i - 1][j - 1] == L)
                    {
                        counter++;
                    }
                    if (b->points[i - 1][j] == L)
                    {
                        counter++;
                    }
                    if (b->points[i][j - 1] == L)
                    {
                        counter++;
                    }
                }
                else if (i == b->h - 1 && j == 0)
                {
                    if (b->points[i - 1][j] == L)
                    {
                        counter++;
                    }
                    if (b->points[i - 1][j + 1] == L)
                    {
                        counter++;
                    }
                    if (b->points[i][j + 1] == L)
                    {
                        counter++;
                    }
                }
                else if (j == 0)
                {
                    for (int z = i - 1; z <= i + 1; z++)
                    {
                        for (int y = j; y <= j + 1; y++)
                        {
                            if (z == i && y == j)
                                continue;
                            else if (b->points[z][y] == L)
                                counter++;
                        }
                    }
                }
                else if (j == b->w - 1)
                {
                    for (int z = i - 1; z <= i + 1; z++)
                    {
                        for (int y = j - 1; y <= j; y++)
                        {
                            if (z == i && y == j)
                                continue;
                            else if (b->points[z][y] == L)
                                counter++;
                        }
                    }
                }
                else if (i == b->h - 1)
                {
                    for (int z = i - 1; z <= i; z++)
                    {
                        for (int y = j - 1; y <= j + 1; y++)
                        {
                            if (z == i && y == j)
                                continue;
                            else if (b->points[z][y] == L)
                                counter++;
                        }
                    }
                }
                else if (i == 0)
                {
                    for (int z = i; z <= i + 1; z++)
                    {
                        for (int y = j - 1; y <= j + 1; y++)
                        {
                            if (z == i && y == j)
                                continue;
                            else if (b->points[z][y] == L)
                                counter++;
                        }
                    }
                }
                if (b->points[i][j] == L)
                {
                    if (counter == 2 || counter == 3)
                    {
                        newBoard->points[i][j] = L;
                    }
                    else
                    {
                        newBoard->points[i][j] = D;
                    }
                }
                else
                {
                    if (counter == 3)
                    {
                        newBoard->points[i][j] = L;
                    }
                }
                counter = 0;
            }
        }
        return setNewBoard(newBoard, gen - 1);
    }
    return b;
}

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
    if (w <= 0 || h <= 0)
        return NULL;
    board_t b = createBoard(w, h);
    b->w = w;
    b->h = h;
    int new;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (fscanf(f, "%d", &new) == 1)
            {
                if (new == 0 || new == 255)
                {
                    b->points[i][j] = new;
                }
                else
                {
                    return NULL;
                }
            }
        }
    }
    return b;
}

void printBoard(board_t b)
{
    for (int i = 0; i < b->h; i++)
    {
        for (int j = 0; j < b->w; j++)
        {
            printf("%d ", b->points[i][j]);
        }
        printf("\n");
    }
}