# Fixed Point Iteration Method
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