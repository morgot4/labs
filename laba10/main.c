#include <stdlib.h>
#include <stdio.h>

void print_1(int, int, int*);
void print_2(int, int, int*);

//создаем динамический массив (аналог вектора) с изначальной длиной 4, далее с удваиваем 
//используем malloc для начального выделения памяти
//используем realloc для выделения памяти для массива с удвоенной длиной
//используем free для освобождения выделенной памяти


typedef struct {
    int *data;   //указатель на область в памяти, где находиться начальный (нулевой элемент)
    size_t size; //размер (длина) массива
    size_t capacity; // размер (физическая длина) массива

} Vector;

void vector_init(Vector *v) {

    v->size = 0;  //изначально пустой         
    v->capacity = 4; //выделим память на 4 элемента
    v->data = (int *)malloc(v->capacity * sizeof(int)); // выделяем память в размере: количество элементов * величину одного (величину int-а)
}

void vector_push_back(Vector *v, int value) {
    if (v->size == v->capacity) { //проверка переполняемости
        v->capacity *= 2;          //удваиваем физическую длину
        v->data = (int *)realloc(v->data, v->capacity * sizeof(int)); //перевыделяем память для нового capacity
    }
    v->data[v->size++] = value; //добавляем в конец value
}

void vector_free(Vector *v) {
    free(v->data); // освобождаем память, далее обнуляем значения
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;  // Делим массив пополам (зная середину, левую и правую границу)
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int)); // выделяем память для левой половины и правой половины
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)  // заполняем область памяти левой и правой половину соответствующими значениями
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;  //алгоритм соединения двух отсортированных массивов (при помощи рекурсии гарантируется их упорядоченность)
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

//Функция для отладки имеет одновременно и прямую и косвенную рекурсию, 
void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);   //Прямая рекурсия
        merge_sort(arr, mid + 1, right); //Прямая рекурсия
        merge(arr, left, mid, right);
    }
}

//Косвенная рекурсия для вывода массива без цикла
void print_1(int n, int c, int* arr){
    if (c < n){
        printf("%d ", arr[c]);
        c++;
        print_2(n, c, arr);
    }
    else
        return; 
}

void print_2(int n, int c, int* arr){
    if (c < n){
        printf("%d ", arr[c]);
        c++;
        print_1(n, c, arr);
    }
    else
        return;
}


int main() {
    Vector v;
    vector_init(&v);

    // Заполняем массив значениями
    vector_push_back(&v, 10);
    vector_push_back(&v, 3);
    vector_push_back(&v, 15);
    vector_push_back(&v, 7);
    vector_push_back(&v, 8);
    vector_push_back(&v, 23);

    merge_sort(v.data, 0, v.size - 1);
    printf("%d\n", v.size);

    print_1(v.size, 0, v.data);

    vector_free(&v);
    return 0;
}