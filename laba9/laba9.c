#include <stdio.h>
#include <stdbool.h>
#include "laba9.h"


void test(){
    FILE *max_ft = fopen("unit_tests\\data\\max_data.txt", "w");
    FILE *min_ft = fopen("unit_tests\\data\\min_data.txt", "w");
    FILE *div_ft = fopen("unit_tests\\data\\div_data.txt", "w");
    FILE *mod_ft = fopen("unit_tests\\data\\mod_data.txt", "w");
    for (int i = -100; i < 100; i++){
        for (int j = -100; j < 100; j++){
            fprintf(max_ft, "%d\t%d\t%d\n", i, j, max(i, j));
            fprintf(min_ft, "%d\t%d\t%d\n", i, j, min(i, j));
            if (j != 0){
                fprintf(div_ft, "%d\t%d\t%d\n", i, j, div(i, j));
                fprintf(mod_ft, "%d\t%d\t%d\n", i, j, mod(i, j));
            }
        }
    }
    fclose(max_ft);fclose(min_ft);fclose(div_ft);fclose(mod_ft);
}
\

int mod(int a, int b)
{
    return a - div(a, b) * b;
}

int div(int a, int b)
{   if (((a < 0 && b > 0) || ((a > 0 && b < 0))) && a % b != 0)
        return (a / b) - 1;
    else
        return (a / b);
}

int max(int a, int b){
    return a>b?a:b;
}

int min(int a, int b){
    return a<b?a:b;
}

int I(int i, int j, int l, int k){
    return mod((i*i*i - j*j*j + l*l*l - k), 20);
}

int J(int i, int j, int l, int k){
    return mod(min(min(i*j*j - k, i*i*l - k), min(i*i*l - k, j*l*l - k)), 30);
}

int L(int i, int j, int l, int k){
    return mod(max(max(i*j*j - k, i*i*l - k), max(i*i*l - k, j*l*l - k)), 30);
}

bool inCircle(int x, int y, int x0, int y0, int r){
    return (x - x0)*(x - x0) + (y - y0)*(y - y0) <= r*r;
}


int main(void){

    int i_p = 6, j_p = 27, l_p = -15, i, j, l;
    int flag = 0, k=0;

    test();
    FILE *ft = fopen("gnuplot\\position.txt", "w");
    while (flag != 1 && k <= 50){
        fprintf(ft, "%d\t%d\t\n", i, j);
        if (inCircle(i_p, j_p, -10, -10, 10) && inCircle(i_p, j_p, -20, -20, 10)){
            flag = 1;
            printf("k: %d, i: %d j: %d l: %d YES\n", k, i_p, j_p, l_p);
            k++;
            break;
            
        }
        else{
            fprintf(ft, "%d\t%d\n", i, j);
            printf("i: %d j: %d l: %d k: %d\n", i_p, j_p, l_p, k);
            i = I(i_p, j_p, l_p, k);
            j = J(i_p, j_p, l_p, k);
            l = L(i_p, j_p, l_p, k);
            i_p = i; j_p = j; l_p = l;

            k++;
        }
        
            
    }
    if (!flag){
        printf("No \n");
    }
    fclose(ft);

    
}

