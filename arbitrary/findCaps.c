#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>

size_t *find_capitals(const char *word, size_t *uppercase_count) {
    size_t len = 0;
    while (word[len] != '\0') len++;

    *uppercase_count = 0;
    for (size_t i = 0; i < len; i++) {
        if (isupper((unsigned char)word[i])) {
            (*uppercase_count)++;
        }
    }

    size_t *indices = malloc(*uppercase_count * sizeof(size_t));
    if (!indices) return NULL;

    size_t j = 0;
    for (size_t i = 0; i < len; i++) {
        if (isupper((unsigned char)word[i])) {
            indices[j++] = i;
        }
    }

    return indices;
}
