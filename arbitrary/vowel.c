#include <stddef.h>

char getCap(char letter) {
    if (letter > 'Z') return letter - ('a' - 'A');
    return letter;
}

size_t get_count(const char *s)
{
    size_t count = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (
            getCap(s[i]) == 'A' ||
            getCap(s[i]) == 'E' ||
            getCap(s[i]) == 'I' ||
            getCap(s[i]) == 'O' ||
            getCap(s[i]) == 'U'
        ) {
            count++;
        }
    }
    return count;
}