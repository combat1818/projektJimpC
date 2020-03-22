
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <fcntl.h>
#include "board.h"

char *usage =
    "\nPrawidłowe użytkowanie programu:\n\n"
    "--- 2 opcje wywołania ---\n"
    "* make generate - tworzy plik tekstowy o zadanej wielkości\n"
    "* make run - tworzy program w którym jako argumenty podajemy: \n"
    "-f - po tej fladze podajemy plik startowy\n"
    "-g - po tej fladze podajemy ilość generacji\n"
    "przykład poprawnego wywołania: ./a.out -f tab.txt -g 6\n"
    "(czyli czytamy z pliku tab.txt i tworzymy 6 generacji - 6 plików w formacie .png)\n"
    "Plik tekstowy powinien zawierać: \n"
    "2 liczby całkowite większe od 0 jako reprezentacje szerokości i wysokości obrazka, \n"
    "tabele uporządkowaną liczbami 0 lub 255 jako reprezentacje pikseli na obrazku, np: \n"
    "3 3\n"
    "0 0 0\n"
    "0 0 0\n"
    "0 0 0\n\n";

int main(int argc, char **argv)
{
  int opt;
  int gen;
  char *fname;
  while ((opt = getopt(argc, argv, "f:g:")) != -1)
  {
    switch (opt)
    {
    case 'f':
      fname = optarg;
      break;
    case 'g':
      gen = atoi(optarg);
      break;
    default:
      printf("%s", usage);
    }
  }
  if (fname == NULL)
  {
    printf("(BŁĄD PLIKU STARTOWEGO) Brak pliku startowego\n");
    printf("%s", usage);
    return 1;
  }
  FILE *f = fopen(fname, "r");
  if (f == NULL)
  {
    printf("(BŁĄD PLIKU STARTOWEGO) Nie ma takiego pliku \n");
    printf("%s", usage);
    return -1;
  }
  board_t board = fillBoard(f);
  if (board == NULL)
  {
    printf("(BŁĄD PLIKU STARTOWEGO) Brak wymiarów w pliku, bądź nieprawidłowe liczby. \n");
    printf("%s", usage);
    return -1;
  }
  // process_file(board, board->h, board->w);
  // write_png_file('test.png', board->h, board->w);

  /* process_file(board, 1000, 1000);   
  write_png_file("outZ.png", 1000 , 1000);*/
  board_t x = setNewBoard(board, gen, gen);
  return 0;
}
