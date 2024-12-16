#include <stdio.h>
#include <math.h>
#include <stdbool.h>


typedef struct
{
    double root;
    int iters;
    bool succes;
}answer;
 

double F1(double x){
    return log(x) - x + 1.8;
}

double F1_for_iters(double x){
    return log(x) + 1.8;
}

double F2(double x){
    return (x * tan(x)) - (1.0 / 3);
}

double F2_for_iters(double x) {
    return x - 0.5 * (x * tan(x) - 1.0 / 3.0);
}


typedef double (*func)(double);;

double df(func f, double x){
    double dx = 1e-6;
    return (f(x + dx) - f(x - dx)) / (2 * dx);
}

double ddf(func f, double x){
    double dx = 1e-6;
    return (f(x + dx) - 2*f(x) + f(x - dx)) / (dx * dx);
}

answer diho(double a, double b, func f){
    answer res = {.root=0, .iters=0, .succes=false};
    if (f(a) * f(b) <= 0)
        res.succes = true;
    else{
        res.succes = false;
        return res;
    }
    double apr = 0.0001;
    double mid=0;
    while (a + apr <= b){
        mid = (a + b) / 2.0;
        if (f(mid) == 0){
            res.root = mid;
            break;
        }
        else if (f(mid) * f(b) < 0){
            a = mid;
        }
        else
            b = mid;
        res.iters++;
        
    }
    res.root = (a + b) / 2.0;
    return res;
}

answer iterations(func f_for_iters, double x0){
    answer res = {.root=0, .iters=0, .succes=false};
    double apr = 0.00001;
    double x_next = f_for_iters(x0);
    while(fabs(x_next - x0) > apr){

        if (fabs(df(f_for_iters, x0)) >= 1){
            res.succes = false;
            return res;
        }
        x0 = x_next;
        x_next = f_for_iters(x0);
        res.iters++;
    }
    res.root = x_next;
    res.succes = true;
    return res;
}

answer newton(func f, double x0){
    answer res = {.root=0, .iters=0, .succes=false};
    double apr = 0.0001;
    double x_next = x0 - (f(x0) / df(f, x0));
    while(fabs(x_next - x0) > apr){

        if (fabs(f(x0) * ddf(f, x0)) < (df(f, x0) * df(f, x0)))
            res.succes = true;
        else{
            res.succes = false;
            return res;
        }
        x0 = x_next;
        x_next = x0 - (f(x0) / df(f, x0));
        res.iters++;
    }
    res.root = x_next;

    return res;
}

int main(void){
    double interval1[2] = {2.0, 3.0};
    double interval2[2] = {0.2, 1.0};

    // метод дихотомии
    answer ans1 = diho(interval1[0], interval1[1], *F1);
    if (ans1.succes)
        printf("diho ans1: %.4f\niters: %d\n", ans1.root, ans1.iters);
    else
        printf("no success f1\n");

    answer ans2 = diho(interval2[0], interval2[1], *F2);

    if (ans2.succes)
        printf("diho ans2: %.4f\niters: %d\n", ans2.root, ans2.iters);
    else
        printf("no success f2\n");    

    //метод итераций
    ans1 = iterations(F1_for_iters, 2.5);

    if (ans1.succes)
        printf("iterations ans1: %.4f\niters: %d\n", ans1.root, ans1.iters);
    else
        printf("no success f1\n");

    ans2 = iterations(F2_for_iters, 0.5);

    if (ans2.succes)
        printf("iterations ans2: %.4f\niters: %d\n", ans2.root, ans2.iters);
    else
        printf("no success f2\n");
        
    //метод итераций
    ans1 = newton(F1, interval1[1]);
    
    if (ans1.succes)
        printf("newton ans1: %.4f\niters: %d\n", ans1.root, ans1.iters);
    else
        printf("no success f1\n");

    ans2 = newton(F2, interval2[1]);


    if (ans2.succes)
        printf("newton ans2: %.4f\niters: %d\n", ans2.root, ans2.iters);
    else
        printf("no success f2\n");     
    return 0;
    
}