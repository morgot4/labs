#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>

#define ALPHABET_SIZE 34
#define SET_BIT(set, idx)   ((set) |= (1ULL << (idx)))
#define CLEAR_BIT(set, idx) ((set) &= ~(1ULL << (idx)))
#define TEST_BIT(set, idx)  ((set) & (1ULL << (idx)))

void printBinary(uint32_t num) {
    for (int i = sizeof(uint32_t) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int get_index(wchar_t c) {
    
    c = tolower(c);
    if (c >= 'а' && c <= 'я') {
        return c - 'а';
    } else if (c == 'ё') {
        return 33;
    }
    return -1;
}

void print(wchar_t *a){
    setlocale(LC_ALL, "");
    for (; *a != '\0'; a++){
        printf("%lc", *a);
    }
}

int main() {
    uint64_t bitset = 0;
    // Текст для обработки
    wchar_t text = L"Привет, мир! Ёлка и ёжик.";
        

    for (int i = 0; text[i] != '\0'; i++) {
        int index = get_index(text[i]);
        if (index != -1) {
            SET_BIT(bitset, index);
        }
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (TEST_BIT(bitset, i)) {
            printf(L"Буква %c встречается в тексте.\n", (i == 33 ? 'Ё' : 'А' + i));
        }
    }

    return 0;
}
