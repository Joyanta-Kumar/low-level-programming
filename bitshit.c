#include <stdio.h>
#include <stdbool.h>


void setbit(__uint8_t* address, __uint8_t index, bool value);
bool getbit(const __uint8_t* address, __uint8_t index);


int main() {
    return 0;
}


void setbit(__uint8_t* address, __uint8_t index, bool value) {
    if (value)  *address = *address | (1 << index);
    else        *address = *address & ~(1 << index);
}


bool getbit(const __uint8_t* address, __uint8_t index) {
    return (*address >> index) & true;
}
