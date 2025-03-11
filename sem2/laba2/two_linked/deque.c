#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct elem;

typedef struct elem
{
    double value;
    struct elem* next;
    struct elem* prev;

}elem;

typedef struct{
    elem* first;
    elem* last;

}deque;



deque* init(int max_len){

    deque* res = malloc(sizeof(deque));
    if (res == NULL){
        perror("Not enough memory for deque");
        return NULL;
    }
    res->first = NULL;
    res->last= NULL;
    return res;

}

bool push_back(deque* deque, double value){
    elem* e = malloc(sizeof(elem));
    if (e == NULL) {return false;}
    e->value = value;
    e->next = NULL;
    e->prev = deque->last;
    if (deque->last == NULL){
        deque->last = deque->first = e;
    }
    else{
        deque->last->next = e;
        deque->last = e;
    }
    return true;
}

bool push_front(deque* deque, double value){
    elem* e = malloc(sizeof(elem));
    if (e == NULL) {return false;}
    e->value = value;
    e->next = deque->first;
    e->prev = NULL;

    if (deque->first == NULL){
        deque->last = deque->first = e;
    }
    else{
        deque->first->prev = e;
        deque->first = e;
    }
    return true;
}

bool is_empty(deque* deque){
    if (deque->first == NULL){
        return true;
    }
    return false;
}

double pop_front(deque* deque){
    if (is_empty(deque)){
        perror("deque is empty");
    }
    double res = deque->first->value;
    elem* next = deque->first->next;

    if (next != NULL) {
        next->prev = NULL;
    } else {
        deque->last = NULL;
    }

    free(deque->first);
    deque->first = next;
    return res;
    
}


double pop_back(deque* deque){
    if (is_empty(deque)){
        perror("deque is empty");
    }
    double res = deque->last->value;
    elem* prev = deque->last->prev;
    if (prev != NULL) {
        prev->next = NULL;
    } else {
        deque->first = NULL;
    }
    free(deque->last);
    deque->last = prev;
    return res;
    
}

void destroy(deque* deque){
    elem* cur = deque->first;
    while (cur != NULL){
        elem* next = cur->next;
        free(cur);
        cur = next;
    }
    free(deque);

}

void print_deque(deque* deque){
    elem* cur = deque->first;

    while (cur != NULL){
        printf("%f ", cur->value);
        cur = cur->next;
    }
    printf("\n");
}

int main(void){
    deque *deque = init(6);
    push_back(deque, 1);
    push_back(deque, 2);
    push_back(deque, 3);
    push_front(deque, 3);
    print_deque(deque);
    double value = pop_front(deque);
    print_deque(deque);
    printf("value: %f\n", value);
    value = pop_front(deque);
    print_deque(deque);
    printf("value: %f\n", value);
    value = pop_back(deque);
    print_deque(deque);
    printf("value: %f\n", value);
    value = pop_front(deque);
    print_deque(deque);
    printf("value: %f\n", value);
    destroy(deque);

    return 0;
}