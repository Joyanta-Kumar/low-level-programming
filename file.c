#include <stdio.h>

int main() {
  printf("\e[34;1mStarted program...\e[0m\n");

  FILE *file = NULL;
  file = fopen("test.txt", "r");

  if (file == NULL) {
    printf("Error while opening the file.\n");
    return 0;
  }
  printf("File is loaded in memory: %p\n", file);

  int highlight = 0;
  int ch_code = 0;
  while ((ch_code = fgetc(file)) != EOF) {
    if (ch_code == '"') {
      if (highlight == 0) {
        highlight = 1;
      }
      else {
        highlight = 0;
      }
    }
    if (highlight == 1) {
        printf("\e[34m");
    }
    printf("%c", ch_code);
    if (highlight == 0) {
      printf("\e[0m");
    }
  }

  fclose(file);
  return 0;
}
