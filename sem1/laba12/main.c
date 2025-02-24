#include <stdio.h>

int max(int a, int b){
    return a > b ? a : b;
}

int delLast(int a){
    int res=0;
    res = ((res + (a / 100)) * 10) + (a % 10);
    return res;
}

int Count(int a){
    int i=1;
    while(a){
        a/=10;
        i*=10;
    }
    return i / 10;
}


int delSecond(int a){
    int count = Count(a);
    return ((a / count) * (count / 10) + (a % max(10, count / 10)));
}



int del(int a){
    int res=0;
    if (a < 100 && a > -100){
        res += a;
    }
    else if (a < 1000 && a > -1000){
        res = delLast(a);
    
    }
    else{
        res = delLast(a);

        res = delSecond(res);

    }
    
    return res;

}


int main(void){

    int a;

    while (scanf("%d", &a) == 1){
        a = del(a);
        printf("%d\n", a);
    }
    return 0;
}