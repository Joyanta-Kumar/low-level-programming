#include <stddef.h>
#include <stdio.h>

long long sum_two_smallest_numbers(size_t n, const int numbers[n]) {
    long long minimum0 = __INT_MAX__;
    long long minimum1 = minimum0;
    for (int i  = 0; i < n; i++) {
        if (numbers[i] < minimum0) {
            minimum1 = minimum0;
            minimum0 = numbers[i];
        }
        else if (numbers[i] < minimum1 && numbers[i] >= minimum0) {
            minimum1 = numbers[i];
        }
        printf("%d %d\n", minimum0, minimum1);
    }
    return minimum0 + minimum1;
}

int main() {
    int array[] = { 2000000000, 2000000000, 2000000000, 2000000000, 2000000000 };
    sum_two_smallest_numbers(5, array);
}