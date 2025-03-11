#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN = 100

typedef struct{
    int max_len;   // емкость (макс длина)
    int len;   // фактическая длина
    int start;
    int end_plus;
    double *buffer;   // указатель на дабл элемент массива

}deque;



deque* init(int max_len){

    deque* res = malloc(sizeof(deque));
    if (res == NULL){
        perror("Not enough memory for deque");
        return NULL;
    }
    res->max_len = max_len;
    res->len = 0;
    res->start = 0;
    res->buffer = malloc(sizeof(double) * res->max_len);
    if (res->buffer == NULL){
        free(res);
        perror("Not enough memory for deque buffer");
        return NULL;
    }
    return res;

}


bool is_empty(deque* deque){
    if (deque->len == 0){
        return true;
    }
    return false;
}

bool push_back(deque* deque, double value){
    if (deque->len == deque->max_len){
        printf("Deque is full\n");
        return false;
    }

    deque->buffer[(deque->start + deque->len) % deque->max_len] = value;
    deque->len++;
    return true;
    
}

double pop_front(deque* deque){
    if (is_empty(deque)){
        perror("deque is empty");
    }
    double value = deque->buffer[deque->start];
    deque->start = ((deque->start) + 1) % deque->max_len;
    deque->len--;
    return value;
    
    
}

bool push_front(deque* deque, double value){
    if (deque->len == deque->max_len){
        printf("Deque is full\n");
        return false;
    }
    deque->start = (deque->start - 1 + deque->max_len) % deque->max_len; 

    deque->buffer[deque->start] = value;
    deque->len++;
    return true;
    
}


double pop_back(deque* deque){
    if (is_empty(deque)){
        perror("deque is empty");
    }
    double value = deque->buffer[(deque->start + deque->len - 1) % deque->max_len];
    deque->len--;
    return value;
    
    
}


void destroy(deque* deque){
    free(deque->buffer);
    free(deque);

}

void print_deque(deque* deque) {
    for (int i = 0; i < deque->len; i++) {
        int idx = (deque->start + i) % deque->max_len;
        printf("%f ", deque->buffer[idx]);
    }
    printf("\n");
}

int main(void){
    deque *deque = init(10);
    push_back(deque, 1);
    push_back(deque, 2);
    push_back(deque, 3);
    push_back(deque, 4);
    push_back(deque, 5);
    push_back(deque, 6);
    print_deque(deque);
    push_front(deque, 0);
    print_deque(deque);
    push_front(deque, 0);
    print_deque(deque);
    push_front(deque, 0);
    print_deque(deque);
    push_front(deque, 0);
    print_deque(deque);
    pop_back(deque);
    push_back(deque, 1);
    print_deque(deque);
    pop_front(deque);
    push_front(deque, 9);
    print_deque(deque);
    return 0;
}