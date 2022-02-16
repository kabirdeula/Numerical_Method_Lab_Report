# Polynomial Regression

## Algorithm

    1. Start

    2. Read number of points, say n.

    3. Read order of polynomial, say m.

    4. Read give data points, say x[i] and y[i].

    5. Calculate required summations as below,

        For i = 1 to 2m
            For j = 0 to n - 1
                sx[i] = sx[i] + pow(x[j], i)
            End For
        End For
        
        For i = 0 to m
            For j = 0 to n - 1
                sxy[i] = y[j] * pow(x[j], i)
            End For
        End For
    
    6. Construct RHS matrix of order (m + 1) x (m + 1)

    7. Construct LHS matrix of order (m + 1) x 1

    8. Solve for coefficients a0, a1, ..., am using Gauss Elimination Method.

    9. Display the equation y = a0 + a1x + a2x^2 + ... + amx^m

    10. Stop

## Source Code

```c

#include<stdio.h>
#include<math.h>

int main(){

    int m, n, i, j, k;
    float a[20][20], b[20], x[20], y[20], z[20];
    float sum, pivot, term;

    printf("Enter the number of points: ");
    scanf("%d", &n);

    printf("Enter degree of polynomial to be fitted\n");
    scanf("%d", &m);

    printf("Enter the value of x and y:\n");

    for (i = 0; i < n; i++){
        printf("x[%d]: ",i);
        scanf("%f", &x[i]);
        printf("y[%d]: ",i);
        scanf("%f",&y[i]);
    }

    // Construction of cofficient matrix
    for (i = 0; i <= m; i++){
        for (j = 0; j <=m; j++){
            sum = 0;
            for (k = 0; k < n; k++){
                sum += pow(x[k], i + j);
            }
            a[i][j] = sum;
        }
    }

    // Construction of RHS vectors
    for (i = 0; i <= m; i++){
        sum = 0;
        for (k = 0; k < n; k++){
            sum = sum + y[k] * pow(x[k], i);
        }
        b[i] = sum;
    }

    // Forward Elimination
    for (k = 0; k < m; k++){
        pivot = a[k][k];
        if (pivot < 0.00001){
            printf("Method Failed.\n");
        }else{
            for (i = k + 1; i <= m; i++){
                term = a[i][k] / pivot;
                for (j = 0; j <= m; j++){
                    a[i][j] = a[i][j] - a[k][j] * term;
                }
                b[i] = b[i] - b[k] * term;
            }
        }
    }
    z[m] = b[m] / a[m][m];

    // Back Substitution
    for (i = m - 1; i >= 0; i--){
        sum = 0;
        for (j = i + 1; j <= m; j++){
            sum = sum + a[i][j] * z[j];
        }
        z[i] = (b[i] - sum) / a[i][i];
    }

    printf("The polynomial of regression is: ");
    printf("y = %f + %f x", z[0], z[1]);
    
    for (i = 2; i <= m; i++){
        printf("+%f x^%d", z[i], i);
    }
    return 1;
}

```

## Links

[Polynomial Regression](https://github.com/kabirdeula/Numerical_Method_Lab_Report/blob/main/Lab%20Report/Lab11.c)

[Back to Home](../README.md)
