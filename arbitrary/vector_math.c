#include <stdio.h>
#include <stdbool.h>


int parseInt(char *string) {
    bool isNegative = false;
    int number = 0;
    unsigned short index = 0;

    switch (string[0]) {
        case '+': index = 1; break;
        case '-': index = 1; isNegative = true; break;
    }

    if (string[index] == 0) {
        number = 1;
    }

    while (string[index] != '\0') {
        number *= 10;
        number += string[index] - '0';
        index++;
    }
    if (isNegative) {
        number = 0 - number;
    }
    return number;
}


int main(int argc, char **argv) {

    if (argc == 1) {
        printf("Try typing: vector help\n");
        return 1;
    }
    else if (argc == 2) {
        printf("vector [vector] [vector] ... [vector] (this will add the vectors)\n");
        return 0;
    }

    int vector[3] = { 0, 0, 0 };

    for (unsigned short i = 1; i < argc; i++) {
        char buffer[20];
        short buffer_top = -1;
        for (int j = 0; argv[i][j] != '\0'; j++) {            
            buffer[++buffer_top] = argv[i][j];
            if (argv[i][j] == 'i' || argv[i][j] == 'j' || argv[i][j] == 'k') {
                buffer[buffer_top] = '\0';
                buffer_top = -1;
                vector[argv[i][j]-'i'] += parseInt(buffer);
            }
        }
    }

    for (unsigned short i = 0; i < 3; i++) {
        printf("%d ", vector[i]);
    }

    return 0;
}