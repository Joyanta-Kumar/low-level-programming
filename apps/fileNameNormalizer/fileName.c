#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>

// Returns 1 if strings are similar
int strCmp(const char *str1, const char *str2) {
  int index = 0;
  while (1) {
    if (str1[index] == '\0') {
      if (str2[index] == '\0') { return 1; }
      else { return 0; }
    }
    if (str1[index] != str2[index]) { return 0; }
    index += 1;
  }
}

char getSmall(char letter) {
  if (letter >= 'A' && letter <= 'Z') {
    return letter + ('a' - 'A');
  }
  else {
    return letter;
  }
}

char *strCat(char* str1, char* str2) {
  int len1 = 0;
  int len2 = 0;
  int index = 0;

  while (str1[len1] != '\0') { len1++; }
  while (str2[len2] != '\0') { len2++; }

  char *cat = (char*) malloc(1+len1+len2);

  for (int i = 0; i < len1; i++) { cat[index++] = str1[i]; }
  for (int i = 0; i < len2; i++) { cat[index++] = str2[i]; }
  cat[index] = '\0';
  str1 = cat;
  return cat;
}

int main(int argc, char **argv) {
  printf("Program started.\n\n");
  const char *directory_path = (argc > 1) ? argv[1] : ".";
  char *selfName = argv[0];
  struct dirent *entry;

  if (selfName[0] == '.' && selfName[1] == '/') {
    selfName += 2;
  }

  DIR *directory = opendir(directory_path);

  if (directory == NULL) {
    printf("Error while opeining the directory.\n");
    return 0;
  }


  while ((entry = readdir(directory)) != NULL) {
    if (
        strCmp(entry->d_name, ".") ||
        strCmp(entry->d_name, "..") ||
        strCmp(entry->d_name, selfName) ||
        strCmp(entry->d_name, strCat(selfName, ".c")) ||
        strCmp(entry->d_name, "Makefile")
    ) {
      continue;
    }
    int index = 0;
    char c;
    while ((c = entry->d_name[index]) != '\0') {
      if (c == ' ') {
        c = '_';
      }
      printf("%c", getSmall(c)); 
      index++;
    }
    printf("\n");
  }

  closedir(directory);

  return 0;
}
