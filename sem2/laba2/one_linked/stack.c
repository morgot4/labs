#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct elem;

typedef struct elem
{
    double value;
    struct elem* next;

}elem;

typedef struct{
    elem* first;

}stack;



stack* init(int max_len){

    stack* res = malloc(sizeof(stack));
    if (res == NULL){
        perror("Not enough memory for stack");
        return NULL;
    }
    res->first = NULL;
    return res;

}

bool push_back(stack* stack, double value){
    elem* e = malloc(sizeof(elem));
    if (e == NULL) {return false;}
    e->value = value;
    e->next = stack->first;
    stack->first = e;
    return true;
}

bool is_empty(stack* stack){
    if (stack->first == NULL){
        return true;
    }
    return false;
}

double pop_back(stack* stack){
    if (is_empty(stack)){
        perror("Stack is empty");
    }
    double res = stack->first->value;
    elem* next = stack->first->next;
    free(stack->first);
    stack->first = next;
    return res;
    
    
}


void destroy(stack* stack){
    elem* cur = stack->first;
    while (cur != NULL){
        free(cur);
        cur = cur->next;
    }
    free(stack);

}

void print_stack(stack* stack){
    elem* cur = stack->first;
    while (cur != NULL){
        printf("%f ", cur->value);
        cur = cur->next;
    }
    printf("\n");
}

int main(void){
    stack *stack = init(100);
    push_back(stack, 1);
    print_stack(stack);
    push_back(stack, 2);
    print_stack(stack);
    push_back(stack, 3);
    print_stack(stack);
    double value = pop_back(stack);
    printf("%f\n", value);
    print_stack(stack);
    destroy(stack);

    return 0;
}