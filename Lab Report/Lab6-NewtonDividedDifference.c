#include<stdio.h>

int main(){
    int n, i, j;
    float v = 0, p, xv, x[10], fx[10], a[10];
    printf("Enter the number of points: ");
    scanf("%d", &n);
    printf("Enter the value of x: ");
    scanf("%f",&xv);
    for(i = 0; i < n; i++){
        printf("x[%d]: ",i);
        scanf("%f", &x[i]);
        printf("fx[%d]: ",i);
        scanf("%f", &fx[i]);
    }
    for(i = 0; i < n; i++){
        a[i] = fx[i];
    }
    for(i = 0; i < n; i++){
        for(j = n - 1; j > i; j --){
            a[j] = (a[j] - a[j - 1])/(x[j] - x[j - 1 - i]);
        }
    }
    v = 0;
    for(i = 0; i < n; i++){
        p = 1;
        for(j = 0; j <= i-1; j++){
            p = p * (xv - x[j]);
        }
        v =  v + a[i] * p;
    }
    printf("Interpolation value = %f\n",v);
}