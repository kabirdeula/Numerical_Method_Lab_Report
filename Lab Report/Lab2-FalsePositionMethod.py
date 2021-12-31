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