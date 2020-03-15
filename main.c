
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <fcntl.h>
#include "board.h"

char *usage =
    "\nPrawidłowe użytkowanie programu:\n"
    "-f - po tej fladze podajemy plik startowy np: ./a->out -f tab->txt \n"
    "-g - po tej fladze podajemy ilość generacji np: ./a->out -f tab->txt -g 6 \n"
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
  board_t board = fillBoard(f);
  if (board == NULL)
  {
    printf("(BŁĄD PLIKU STARTOWEGO) Brak wymiarów w pliku, bądź nieprawidłowe liczby-> \n");
    printf("%s", usage);
    return -1;
  }

  
		
 /* process_file(board, 1000, 1000);   
  write_png_file("outZ.png", 1000 , 1000);*/
  board_t x = setNewBoard(board, gen);
  return 0;
}
