#include "pngCreator.h"
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>

char *usage = 
    "\nPrawidłowe użytkowanie programu:\n"
    "-f - po tej fladze podajemy plik startowy np: ./a.out -f tab.txt \n"
    "Plik tekstowy powinien zawierać: \n"
    "2 liczby całkowite większe od 0 jako reprezentacje szerokości i wysokości obrazka, \n"
    "tabele uporządkowaną liczbami od 0 do 255 jako reprezentacje pikseli na obrazku, np: \n"
    "3 3\n"
    "0 0 0\n"
    "0 0 0\n"
    "0 0 0\n\n";

int main(int argc, char **argv)
{
    int opt;
    char *fname;
    while ((opt = getopt(argc, argv, "f:")) != -1)
  {
    switch (opt)
    {
    case 'f':
      fname = optarg;
      break;
    default: 
      printf("%s",usage);
    }
  }
    if(fname==NULL){
        printf("(BŁĄD PLIKU STARTOWEGO) Brak pliku startowego\n");
         printf("%s",usage);
        return 1;
    }
    FILE *f = fopen(fname, "r");
    board_t board = fillBoard(f);
    if(board == NULL){
        printf("(BŁĄD PLIKU STARTOWEGO) Brak wymiarów w pliku, bądź nieprawidłowe liczby. \n");
         printf("%s",usage);
        return -1;
    }
    printBoard(board);
    return 0;
}