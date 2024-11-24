#include "math_ops.h"

//float global_variable = 10.0; //(4) КОМПИЛЯЦИЯ Разные типы данных. int в заголовочном файле math_ops.h, float в math_ops.c


int add(int a, int b) {
    //global_func(); // (7) ЛИНКОВКА использование неопределенной функции
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

int main(int a, int b){  // (8) ЛИНКОВКА второе определение функции main multiple definition of `main'
    return a + b * b;
}