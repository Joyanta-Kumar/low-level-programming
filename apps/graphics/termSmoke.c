#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#define ROWS 20
#define COLS 40

void printChar(bool value) {
  if (value == 0) {
    printf("\e[30m⋄ \e[0m");
  }
  else {
    printf("\e[97m⬦ \e[0m");
  }
}

int main() {
  srand(time(NULL));

  bool grid[ROWS][COLS];    

  system("clear");

  while (true) {

    for (int i = 0; i < ROWS-1; i++) {
      for (int j = 0; j < COLS; j++) {
        grid[i][j] = grid[i+1][j];
        printChar(grid[i][j]);
      }
      printf("\n");
    }

    for (int i = 0; i < COLS; i++) {
      grid[ROWS-1][i] = rand() % 6 == 0;
      printChar(grid[ROWS-1][i]);
    }
    printf("\n");

    usleep(10000);
    system("clear");
  }
  return 0;
}
