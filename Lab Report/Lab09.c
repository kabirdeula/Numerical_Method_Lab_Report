#include<stdio.h>
#include<math.h>

int main(){

    int n, i, j, k, xp;
    float h[10], x[10], fx[10], u[10], v[10], b[10], m[10][10], r[10], e[10];
    float val, pivot, sum;

    printf("Enter Number of Points: ");
    scanf("%d", &n);

    printf("Enter Sample Points:\n");
    for (i = 0; i < n; i++){
        scanf("%f%f", &x[i], &fx[i]);
    }

    printf("Enter Interpolation Point: ");
    scanf("%d", &xp);

    for(i = 0; i < n - 1; i++){
        h[i] = x[i + 1] - x[i];
        b[i] = (fx[i+1] - fx[i])/ h[i];
    }

    for(i = 1; i <= n; i++){
        u[i] = 2 * (h[i - 1] + h[i]);
        v[i] = 6 * (b[i] - b[i - 1]);
    }

    // Construction of matrix in LHS.
    for(i = 1; i < n; i++){
        m[i][i] = u[i];
        if(i != 1){
            m[i][i - 1] = h[i - 1];
            m[i - 1][i] = h[i - 1];
        }
        r[i] = v[i]; // RHS Vector
    }

    // Forward Elimination
    for(k = 1; k < n - 2; k++){
        pivot = m[k][k];
        if (pivot < 0.000001){
            printf("Method Failed\n");
        }else{
            for(i = k + 1; i < n - 1; i++){
                for(j = 1; j < n - 1; j++){
                    m[i][j] = m[i][j] - m[k][j] * m[i][k] / pivot;
                }
                r[i] = r[i] - r[k] * m[i][k] / pivot;
            }
        }
    }

    e[n - 2] = r[n - 2] / m[n - 2][n - 2];

    // Back Substitution
    for(i = n - 3; i >= 1; i--){
        sum = 0;
        for(j = i + 1; j < n - 1; j++){
            sum = sum + m[i][j] * e[j];
        }
        e[i] = (r[i] - sum) / m[i][i];
    }

    // Locating interval in which interpolation point lies
    for(i = 0; i <= n - 1; i++){
        if (xp <= x[i]){
            break;
        }
        i = i - 1;
    }

    // Calculation of interpolated value
    val = (e[i + 1] / (6 * h[i]) * (xp - x[i]) * (xp - x[i]) * (xp - x[i])) + (e[i] / (6 * h[i]) * (x[i + 1] - xp) * (x[i + 1] - xp) * (x[i + 1] - xp)) + (((fx[i + 1] / h[i]) - (e[i + 1] * h[i] / 6)) * (xp - x[i])) + (((fx[i] / h[i]) - (e[i] * h[i] / 6)) * (x[i + 1] - xp));

    printf("Interpolated value = %f\n", val);
    return 1;
}