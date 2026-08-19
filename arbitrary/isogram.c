#include <stdio.h>
#include <stdbool.h>

bool getBit(int *address, unsigned short index) {
    return (*address) >> index & 1;
}
void setBit(int *address, unsigned short index, unsigned short value) {
    if (value == 0) { (*address) = (*address) & ~(1 << index); }
    else { (*address) = (*address) | 1 << index; }
}

char getCap(char letter) {
    if (letter > 'Z') return letter - ('a' - 'A');
    return letter;
}

bool IsIsogram(const char *string) {
    int flag = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        unsigned short int index = getCap(string[i]) - 'A';
        if (getBit(&flag, index) == 1) {
            return false;
        }
        setBit(&flag, index, 1);
    }
    return true;
}

int main() {
    printf("%d\n", IsIsogram("aA"));
}