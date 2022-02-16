#include<stdio.h>

int main(){

    int n, i, j, k;
    float factor, term, vod, xv, x[10], y[10], a[10];

    printf("Enter the number of points: ");
    scanf("%d", &n);

    printf("Enter the value at which derivative is required: ");
    scanf("%f", &xv);

    printf("Enter the value of x and y:\n");
    for (i = 0; i < n; i++){
        printf("x[%d]: ",i);
        scanf("%f", &x[i]);
        printf("y[%d]: ",i);
        scanf("%f",&y[i]);
    }

    // Calculating divided difference
    for (i = 0; i < n; i++){
        a[i] = y[i];
    }
    for (i = 0; i < n; i++){
        for (j = n - 1; j > i; j--){
            a[j] = (a[j] - a[j - 1]) / (x[j] - x[j - 1 - i]);
        }
    }

    // Calculating value of derative
    vod = a[1];
    for (i = 2; i < n; i++){
        term = 0;
        for (j = 0; j < i; j++){
            factor = 1;
            for (k = 0; k < i; k++){
                if (k != j){
                    factor = factor * (xv - x[k]);
                }
            }
            term += factor;
        }
        vod = vod + (a[i] * term);
    }

    printf("Value of First Derivative: %f\n", vod);
    return 0;
}