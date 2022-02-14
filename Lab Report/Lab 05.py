# Importing NumPy Library
import numpy as np

# Reading number of unknowns
n = int(input('Enter number of data points: '))

# Making numpy array of n & n x n size and initializing 
# to zero for storing x and y value along with difference of y
x = np.zeros((n))
y = np.zeros((n))

# Reading data points
print('Enter data for x and y: ')
for i in range(n):
  x[i] = float(input( 'x['+str(i)+']='))
  y[i] = float(input( 'y['+str(i)+']='))

# Reading interpolation point 
xp = float(input('Enter polation point: '))

# Set interpolated value initially to zero
yp = 0

# Implementing Lagrange Interpolation
for i in range(n):
  p = 1
  for j in range(n):
    if i != j:
      p = p*(xp - x[j])/(x[i] - x[j])
    
  yp = yp +p * y[i]

# Displaying output
print('Interpolated value at %.3f is %.3f.'%(xp,yp))

""" Test case 1
Number of data points: 5
Data for x and y:
x0 = 5
y0 = 150
x1 = 7
y1 = 392
x2 = 11
y2 = 1452
x3 = 13
y3 = 2366
x4 = 17
y4 = 5202
Interpolation point: 9
Expected output 
Interpolated value at 9 is 810
"""