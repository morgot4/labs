#include <stdio.h>

int max(int a, int b){
    return a > b ? a : b;
}

int pow(int a, int b){
    int res = 1;
    for (int i=0; i < b; ++i){
        res*= a;
    }
    return res;
}

int delLast(int a){
    int i=0,k=0, res=0;
    res = ((res + (a / 100)) * 10) + (a % 10);
    return res;
}

int Count(int a){
    int i=0;
    while(a){
        a/=10;
        i++;
    }
    return i;
}


int delSecond(int a){
    int i=0,k=0, res=0;
    int count = Count(a);
    return ((a / pow(10, count - 1)) * pow(10, count - 2)) + (a % max(10, pow(10, count - 2)));
}


int del(int a){
    int res=0;
    if (a < 100){
        res += a;
    }
    else if (a < 1000){
        res = delLast(a);
    
    }
    else{
        res = delLast(a);

        res = delSecond(res);

    }
    
    return res;

}


int main(void){

    int a,flag;

    while ((flag = scanf("%d", &a)) != 0){
        a = del(a);
        printf("%d\n", a);
    }
    return 0;
}