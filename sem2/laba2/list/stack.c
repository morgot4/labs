#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int max_len;   // емкость (макс длина)
    int len;   // фактическая длина
    double *buffer;   // указатель на дабл элемент массива

}stack;


stack* init(int max_len){

    stack* res = malloc(sizeof(stack));
    if (res == NULL){
        perror("Not enough memory for stack");
        return NULL;
    }
    res->max_len = max_len;
    res->len = 0;
    res->buffer = malloc(sizeof(double) * res->max_len);
    if (res->buffer == NULL){
        free(res);
        perror("Not enough memory for stack buffer");
        return NULL;
    }
    return res;

}

bool stdb_push_back(stack* stack, double value){
    if (stack->max_len== stack->len){
        return false;
    }
    stack->buffer[stack->len++] = value;
    return true;
}

bool is_empty(stack* stack){
    if (stack->len == 0){
        return true;
    }
    return false;
}

double stdb_pop_back(stack* stack){
    if (is_empty(stack)){
        perror("Stack is empty");
    }
    double value = stack->buffer[stack->len-1];
    stack->len--;
    return value;
    
    
}


void destroy(stack* stack){
    free(stack->buffer);
    free(stack);

}

void print_stack(stack* stack){
    for (int i = 0; i < stack->len; i++){
        printf("%f ", stack->buffer[i]);
    }
    printf("\n");
}

int main(void){
    stack *stack = init(100);
    stdb_push_back(stack, 1);
    stdb_push_back(stack, 2);
    stdb_push_back(stack, 3);
    print_stack(stack);
    double value = stdb_pop_back(stack);
    printf("%f\n", value);
    print_stack(stack);

    return 0;
}