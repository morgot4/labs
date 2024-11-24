#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

#define ALPHABET_SIZE 34


#define SET_BIT(set, idx)   ((set) |= (1ULL << (idx)))
#define CLEAR_BIT(set, idx) ((set) &= ~(1ULL << (idx)))
#define TEST_BIT(set, idx)  ((set) & (1ULL << (idx)))

int get_index(char c) {
    c = tolower(c);
    if (c >= 'а' && c <= 'я') {
        return c - 'а';
    } else if (c == 'ё') {
        return 33;
    }
    return -1;
}

int main() {
    uint64_t bitset = 0;

    // Текст для обработки
    char text[] = "Привет, мир! Ёлка и ёжик.";

    for (int i = 0; text[i] != '\0'; i++) {
        int index = get_index(text[i]);
        if (index != -1) {
            SET_BIT(bitset, index);
        }
    }
    // Проверим, какие буквы встречались
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (TEST_BIT(bitset, i)) {
            printf("Буква %c встречается в тексте.\n", (i == 33 ? 'Ё' : 'А' + i));
        }
    }

    return 0;
}
