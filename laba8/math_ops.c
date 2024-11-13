#include "math_ops.h"

//float global_variable = 10; //(4) КОМПИЛЯЦИЯ Неявное приведение типа. int в заголовочном файле math_ops.h, float в math_ops.c

int add(int a, int b) {
    //global_func(a); // (7) ЛИНКОВКА ошибка из-за отсутствия определения функции
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b == 0) {
        return 0;
    }
    return a / b;
}

// int main(int a, int b){  // (8) ЛИНКОВКА второе определение функции main multiple definition of `main'
//     return a + b * b;
// }