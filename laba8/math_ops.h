//#include "main.c" // (1) ПРЕПРОЦЕССОР ошибка: циклическое подключение

extern int global_variable;
extern void global_func();
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);