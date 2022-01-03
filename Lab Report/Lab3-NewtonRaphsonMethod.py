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