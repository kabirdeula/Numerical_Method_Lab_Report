# Linear Regression

## Algorithm

    1. Start

    2. Read number of points, say n.

    3. Read give data points, say x[i] and y[i].

    4. Find summations of x, y, xy and x² as below,

        For i = 0 to n - 1
            sx = sx + x[i]
            sy = sy + y[i]
            sxy = sxy + x[i] * y[i]
            sx2 = sx2 + x[i] * x[i]
        End For
    
    5. Calculate values of parameters as below,

        b = ((n * sxy) - (sx * sy)) / ((n * sx2) - (sx * sx)) and
        a = (sy /n) - (b * sx / n)
    
    6. Display the equation ax + b

    7. Stop

## Source Code

```c

#include<stdio.h>

int main(){

    int n, i, j, k;
    float a = 0, b =0, x[10], y[10], sx = 0, sy = 0, sxy = 0, sx2 = 0;
    
    printf("Enter the number of points: ");
    scanf("%d", &n);

    printf("Enter the value of x and y:\n");

    for (i = 0; i < n; i++){
        printf("x[%d]: ",i);
        scanf("%f", &x[i]);
        printf("y[%d]: ",i);
        scanf("%f",&y[i]);
    }

    for (i = 0; i < n; i++){

        sx = sx + x[i];
        sy = sy + y[i];
        sxy = sxy + x[i] * y[i];
        sx2 = sx2 + x[i] * x[i];
    }

    b = ((n * sxy) - (sx * sy))/ ((n * sx2) - (sx * sx));
    a = (sy / n) - (b * sx / n);
    
    printf("Fitted line is : %f + %f x\n", a, b);
    return 1;
}

```

## Output

![Linear Regression](./assets/10.png)

## Links

[Linear Regression](https://github.com/kabirdeula/Numerical_Method_Lab_Report/blob/main/Lab%20Report/Lab10.c)

[Back to Home](README.md)
