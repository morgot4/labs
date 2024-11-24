#include <stdio.h>
#include "math_ops.h"

//#define (VALUE) 15 // (2) ПРЕПРОЦЕССОР некорректное имя макроса

#define VALUE 1



int main() {
    int x = 10, y = 5, a=1;

    printf("x + y = %d\n", add(x, y));
    printf("x - y = %d\n", subtract(x, y));
    printf("x * y = %d\n", multiply(x, y));
    printf("x / y = %d\n", divide(x, y));
    //printf("all clear\n"  // (3) КОМПИЛЯЦИЯ Пропущена закрывающая скобка


    // (5) АССЕМБЛИРОВАНИЕ Ассемблерная вставка с ошибкой (В реальном ассемблере такой команды не существует)

    // __asm__ (
    //     "invalid_instruction;" // Error: no such instruction: `invalid_instruction'
    // );

    // (6) АССЕМБЛИРОВАНИЕ Ассемблерная вставка с ошибкой

    // __asm__ (
    //     "mov $5, %%eax;"  // Использование неправильного регистра %%eax

    // );

    printf("x = %d\n", a);
    return 0;
}
