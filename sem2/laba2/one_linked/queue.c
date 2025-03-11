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
    elem* last;

}queue;



queue* init(int max_len){

    queue* res = malloc(sizeof(queue));
    if (res == NULL){
        perror("Not enough memory for queue");
        return NULL;
    }
    res->first = NULL;
    res->last= NULL;
    return res;

}

bool push_back(queue* queue, double value){
    elem* e = malloc(sizeof(elem));
    if (e == NULL) {return false;}
    e->value = value;
    e->next = NULL;
    if (queue->last  == NULL){
        queue->last = queue->first = e;
    }
    else{
        queue->last->next = e;
        queue->last = e;
    }
    return true;
}

bool is_empty(queue* queue){
    if (queue->first == NULL){
        return true;
    }
    return false;
}

double pop_front(queue* queue){
    if (is_empty(queue)){
        perror("queue is empty");
    }
    double res = queue->first->value;
    elem* next = queue->first->next;
    free(queue->first);
    queue->first = next;
    if (queue->first == NULL){
        queue->last = NULL;
    }
    return res;
    
    
}


void destroy(queue* queue){
    elem* cur = queue->first;
    while (cur != NULL){
        free(cur);
        cur = cur->next;
    }
    free(queue);

}

void print_queue(queue* queue){
    elem* cur = queue->first;
    while (cur != NULL){
        printf("%f ", cur->value);
        cur = cur->next;
    }
    printf("\n");
}

int main(void){
    queue *queue = init(5);
    push_back(queue, 1);
    push_back(queue, 2);
    push_back(queue, 3);
    print_queue(queue);
    double value = pop_front(queue);
    value = pop_front(queue);
    value = pop_front(queue);
    value = pop_front(queue);
    printf("%f\n", value);
    print_queue(queue);
    destroy(queue);

    return 0;
}