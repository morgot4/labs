#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN = 100

typedef struct{
    int max_len;   // емкость (макс длина)
    int len;   // фактическая длина
    int start;
    double *buffer;   // указатель на дабл элемент массива

}queue;


queue* init(int max_len){

    queue* res = malloc(sizeof(queue));
    if (res == NULL){
        perror("Not enough memory for queue");
        return NULL;
    }
    res->max_len = max_len;
    res->len = 0;
    res->start = 0;
    res->buffer = malloc(sizeof(double) * res->max_len);
    if (res->buffer == NULL){
        free(res);
        perror("Not enough memory for queue buffer");
        return NULL;
    }
    return res;

}


bool is_empty(queue* queue){
    if (queue->len == 0){
        return true;
    }
    return false;
}

bool qudl_push_back(queue* queue, double value){
    if (queue->max_len == queue->len){
       return false;
    }

    queue->buffer[(queue->start + queue->len) % queue->max_len] = value;
    queue->len++;
    return true;
    
}

double qudl_pop_front(queue* queue){
    if (is_empty(queue)){
        perror("queue is empty");
    }
    double value = queue->buffer[queue->start];
    queue->start = ((queue->start) + 1) % queue->max_len;
    queue->len--;
    return value;
    
    
}


void destroy(queue* queue){
    free(queue->buffer);
    free(queue);

}

void print_queue(queue* queue){
    for (int i = queue->start; i < (queue->start + queue->len); i++){
        printf("%f ",queue->buffer[i]);
    }
    printf("\n");
}


int main(void){
    queue *queue = init(100);
    qudl_push_back(queue, 1);
    qudl_push_back(queue, 2);
    qudl_push_back(queue, 3);
    print_queue(queue);
    double value = qudl_pop_front(queue);
    printf("%f\n", value);
    print_queue(queue);

    return 0;
}