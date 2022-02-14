# False Position Method

## Algorithm

    1. Start

    2. Define function f(x)

    3. Choose initial guesses x0 and x1 such that f(x0)f(x1) < 0

    4. Choose pre-specified tolerable error e.

    5. Calculate new approximated root as: 
    
       x2 = x0 - ((x0-x1) * f(x0))/(f(x0) - f(x1))

    6. Calculate f(x0)f(x2)
    	a. if f(x0)f(x2) < 0 then x0 = x0 and x1 = x2
    	b. if f(x0)f(x2) > 0 then x0 = x2 and x1 = x1
    	c. if f(x0)f(x2) = 0 then goto (8)
    
    7. If |f(x2)|>e then goto (5) otherwise goto (8)

    8. Display x2 as root.

    9. Stop

## Source Code

``` python
# Defining equation
def f(x):
    return x**3-5*x-9

# Implementing Regula Falsi Method
def falsi(x0,x1,e):
    step=1
    print("\n\n***Regula Falsi Method***\n\n")
    condition = True
    print('Iteration\tx0\t\tx1\t\tx2\t\tf(x2)\t\tError')

    while condition:
        x2 = x0 - (x1-x0) * f(x0)/( f(x1) - f(x0))
        err = (x2 - x1)/x2
        print('%d\t\t%0.6f\t%0.6f\t%0.6f\t%0.6f\t%0.6f'%(step, x0, x1,x2, f(x2), err))

        if f(x0) * f(x2) < 0:
            x1 = x2
        else:
            x0 = x2

        step = step + 1
        condition = abs(f(x2)) > e

    print('\nRequired root is: %0.8f' % x2)

# Input Section
x0 = float(input('First Guess: '))
x1 = float(input('Second Guess: '))
e = float(input('Tolerable Error: '))

# Checking Correctness of initial guess values and false positioning
if f(x0) * f(x1) > 0.0:
    print('Given guess values do not bracket the root.')
    print('Try Again with different guess values.')
else:
    falsi(x0,x1,e)

```

## Output

![False Position Method](./assets/False-Position-Method.png)

## Link

[False Position Method](https://github.com/kabirdeula/Numerical_Method_Lab_Report/blob/main/Lab%20Report/Lab%2002.py)

[Back to Home](README.md)
