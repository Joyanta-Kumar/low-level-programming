#include <stdio.h>
#include <stdbool.h>

short getBit(int *address, unsigned short index) {
    return (*address) >> index & 1;
}
void setBit(int *address, unsigned short index, unsigned short value) {
    if (value == 0) { (*address) = (*address) & ~(1 << index); }
    else { (*address) = (*address) | 1 << index; }
}

char getCap(char letter) {
    if (letter > 'Z') {
        return letter - ('a' - 'A');
    }
    else {
        return letter;
    }
}

bool is_anagram(const char *s1, const char *s2) {
    int flag_taken = 0;
    int len = 0;
    int len2 = 0;
    while (s1[++len] != '\0') {}
    while (s2[++len2] != '\0') {}

    if (len != len2) {
        return false;
    }

    for (int i = 0; i < len; i++) {
        bool this_one_found = false;
        for (int j = 0; j < len; j++) {
            if (getCap(s1[i]) == getCap(s2[j]) && getBit(&flag_taken, j) == 0) {
                setBit(&flag_taken, j, 1);
                this_one_found = true;
                break;
            }
        }
        if (!this_one_found) {
            return false;
        }
    }
    return true;
}

int main() {
    printf("%d", is_anagram("fok", "oof"));
    printf("%c\n", getCap('A'));
}