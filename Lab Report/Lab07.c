#include<stdio.h>

int fact(int n){
    if(n == 1){
        return 1;
    }else{
        return (n * fact(n - 1));
    }
}

int main(){
    int n, i, j, k;
    float v = 0, p, xp, x[10], fx[10], fd[10], h, s;
    
    printf("Enter the number of points: ");
    scanf("%d", &n);
    
    printf("Enter the value at which interpolated value is needed: ");
    scanf("%f", &xp);
    
    for (i = 0; i < n; i++){
        printf("x[%d]: ",i);
        scanf("%f", &x[i]);
        printf("fx[%d]: ",i);
        scanf("%f",&fx[i]);
    }

    h = x[1] - x[0];
    s = (xp - x[0]) / h;

    for (i = 0; i < n; i++){
        fd[i] = fx[i];
    }

    for (i = 0; i < n; i++){
        for (j = n - 1; j > i; j--){
            fd[j] = (fd[j] - fd[j - 1]);
        }
    }
    v = fd[0];

    for (i = 1; i < n; i++){
        p = 1;
        for (k = 1; k <= i; k++){
            p = p * (s - k + 1);
        }
        v = v + (fd[i] * p) / fact(i);
    }

    printf("Interpolation value = %f\n", v);
    return 0;

}