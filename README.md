# Numerical Method Lab Report

This is a Numerical Method Lab Report made using Python.

# Table of Contents

- [Overview](#overview)
    - [Bisection Method](#bisection-method)
    - [False Position Method](#false-position-method)
    - [Newton Raphson Method](#newton-raphson-method)
    - [Fixed Point Iteration Method](#fixed-point-iteration-method)
    - [Lagrange Interpolation Method](#lagrange-interpolation-method)
- [My Process](#my-process)
- [Author](#author)

# Overview

## Bisection Method

### Algorithm

    1. Start

    2. Define function f(x)

    3. Choose initial guesses x0 and x1 such that f(x0)f(x1) < 0

    4. Choose pre-specified tolerable error e.

    5. Calculate new approximated root as x2 = (x0 + x1)/2

    6. Calculate f(x0)f(x2)
	    a. If f(x0)f(x2) < 0 then x0 = x0 and x1 = x2
	    b. If f(x0)f(x2) > 0 then x0 = x2 and x1 = x1
	    c. If f(x0)f(x2) = 0 then goto (8)
	
    7. If |f(x2)| > e then goto (5) otherwise goto (8)

    8. Display x2 as root.

    9. Stop

### Source Code

``` python 
# Defining equation
def f(x):
    return x**2-4*x-10

# Implementing Bisection method
def bisection(x0,x1,e):
    step = 1
    print("\n\n*** Bisection Method Implementation ***")
    condition = True
    print('Iteration\tx0\t\tx1\t\tx2\t\tf(x2)\t\tError')
    while condition:
        x2 = (x0 + x1)/2
        err = (x2 - x1)/x2
        print('%d\t\t%0.6f\t%0.6f\t%0.6f\t%0.6f\t%0.6f'%(step, x0, x1,x2, f(x2), err))

        if f(x0) * f(x2) < 0:
            x1 = x2
        else:
            x0 = x2

        step += 1
        condition = abs(f(x2)) > e
    
    print("\n Required Root is : %0.8f" % x2)

# Input Section
x0 = float(input('First Guess: '))
x1 = float(input('Second Guess: '))
e = float(input('Tolerable Error: '))

# Checking correctness of initial guess values and bisecting
if f(x0) * f(x1) > 0.0:
    print('Given guess values do not bracket the root.\nTry again with different guess values')
else:
    bisection(x0,x1,e)
```

### Output

![Bisection Method](./assets/Bisection-Method.png)

### Links

[Bisection Method](https://github.com/kabirdeula/Numerical_Method_Lab_Report/blob/main/Lab%20Report/Lab1-BisectionMethod.py)

<button>[Back to Top](#table-of-contents)</button>

## False Position Method

### Algorithm

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

### Source Code

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

### Output

![False Position Method](./assets/False-Position-Method.png)

### Links

[False Position Method](https://github.com/kabirdeula/Numerical_Method_Lab_Report/blob/main/Lab%20Report/Lab2-FalsePositionMethod.py)

<button>[Back to Top](#table-of-contents)</button>

## Newton Raphson Method

### Algorithm

    1. Start

    2. Define function as f(x)

    3. Define first derivative of f(x) as g(x)

    4. Input initial guess (x0), tolerable error (e) 

    5. Initialize iteration counter i = 1

    6. If g(x0) = 0 then print "Mathematical Error" and goto (11) otherwise goto (7) 

    7. Calcualte x1 = x0 - f(x0) / g(x0)

    8. Increment iteration counter i = i + 1

    9. If |f(x1)| > e then set x0 = x1 and goto (6) otherwise goto (11)

    10. Print root as x1

    11. Stop

### Source Code

``` python
# Defining Function
def f(x):
    return x**3 - 5*x - 9

# Defining derivative of function
def g(x):
    return 3*x**2 - 5

# Implementing Newton Raphson Method
def newtonRaphson(x0,e):
    print('\n\n*** NEWTON RAPHSON METHOD IMPLEMENTATION ***')
    step = 1
    flag = 1
    condition = True
    print('Iteration\t\tx1\t\tf(x1)\t\tError')
    while condition:
        if g(x0) == 0.0:
            print('Divide by zero error!')
            break
        
        x1 = x0 - f(x0)/g(x0)
        err = (x1 - x0)/x1
        print('%d\t\t%0.6f\t%0.6f\t\t%0.6f'%(step, x1, f(x1), err))
        
        x0 = x1
        step = step + 1
        
        condition = abs(f(x1)) > e
    
    if flag==1:
        print('\nRequired root is: %0.8f' % x1)
    else:
        print('\nNot Convergent.')

#Note: You can combine above three section like this
x0 = float(input('Enter Guess: '))
e = float(input('Tolerable Error: '))

# Starting Newton Raphson Method
newtonRaphson(x0,e)
```

### Output

![Newton Raphson Method](./assets/Newton-Raphson-Method.png)

### Links

[Newton Raphson Method](https://github.com/kabirdeula/Numerical_Method_Lab_Report/blob/main/Lab%20Report/Lab3-NewtonRaphsonMethod.py)

<button>[Back to Top](#table-of-contents)</button>

## Fixed Point Iteration Method

### Algorithm

    1. Start 

    2. Define function f(x)
    
    3. Define function g(x) which is obtained from f(x)=0 such that x = g(x) and |g'(x) < 1|

    4. Choose initial guess x0, Tolerable Error e

    5. Initialize iteration counter: step = 1

    6. Calculate x1 = g(x0)

    7. Increment iteration counter: step = step + 1 

    8. Set x0 = x1 for next iteration

    9. If |f(x1)| > e then goto step (6) otherwise goto step (10)

    10. Display x1 as root.

    11. Stop

### Source Code

``` python
# Importing math to use sqrt function
import math

def f(x):
    return x*x*x + x*x -1

# Re-writing f(x)=0 to x = g(x)
def g(x):
    return 1/math.sqrt(1+x)

# Implementing Fixed Point Iteration Method
def fixedPointIteration(x0, e):
    print('\n\n*** FIXED POINT ITERATION ***')
    step = 1
    flag = 1
    condition = True
    print('Iteration\tx1\t\tf(x1)\t\tError')
    while condition:
        x1 = g(x0)
        err = (x1 - x0)/x1
        print('%d\t\t%0.6f\t%0.6f\t%0.6f'%(step, x1, f(x1), err))
        
        x0 = x1

        step += 1
        
        condition = abs(f(x1)) > e

    if flag==1:
        print('\nRequired root is: %0.8f' % x1)
    else:
        print('\nNot Convergent.')

# Input Section
x0 = float(input('Enter Guess: '))
e = float(input('Tolerable Error: '))

# Starting Newton Raphson Method
fixedPointIteration(x0,e)
```

### Output

![Fixed Point Iteration Method](./assets/Fixed-Point-Iteration-Method.png)

### Links

[Fixed Point Iteration Method](https://github.com/kabirdeula/Numerical_Method_Lab_Report/blob/main/Lab%20Report/Lab4-FixedPointIterationMethod.py)

<button>[Back to Top](#table-of-contents)</button>

## Lagrange Interpolation Method

### Algorithm

    1. Start

    2. Read number of data (n)

    3. Read data X<sub>i</sub> and Y<sub>i</sub> for i = 1 to n

    4. Read value of independent variables say xp whose corresponding value of dependent say yp is to be determined.

    5. Initialize: yp = 0

    6. For i = 1 to n
        Set p = 1
        For j = 1 to n
            If i != j then
                Calculate p = p * (xp - X<sub>j</sub>)/(X<sub>i</sub> - X<sub>j</sub>)
            End if
        Next j
        Calculate yp = yp + p * Y<sub>i</sub>
       Next i
    
    7. Display value of yp as interpolated value.

    8. Stop

### Source Code

``` python

```

### Output

![Lagrange Interpolation Method](./assets/Lagrange-Interpolation-Method.png)

### Links

[Lagrange Interpolation Method](https://github.com/kabirdeula/Numerical_Method_Lab_Report/blob/main/Lab%20Report/Lab5-LagrangeInterpolationMethod.py)

<button>[Back to Top](#table-of-contents)</button>

# My Process 

## Useful Resources

[Code Sansar](https://www.codesansar.com/numerical-methods/)

<button>[Back to Top](#table-of-contents)</button>

# Author

- Website - [Kabir Deula](https://www.kabirdeula.com.np)

<button>[Back to Top](#table-of-contents)</button>