# Numerical Method Lab Report

|Lab No.|Title|
|:---|:---|
|1|[Bisection Method](https://github.com/kabirdeula/Numerical_Method_Lab_Report/blob/main/Lab%20Report/Lab1-BisectionMethod.py)|
|2|[False Position Method](https://github.com/kabirdeula/Numerical_Method_Lab_Report/blob/main/Lab%20Report/Lab2-FalsePositionMethod.py)|
|3|[Newton Raphson Method](https://github.com/kabirdeula/Numerical_Method_Lab_Report/blob/main/Lab%20Report/Lab3-NewtonRaphsonMethod.py)|

# Algorithm

<details>
    <summary>Bisection Method Algorithm</summary>

    1. start

    2. Define function f(x)

    3. Choose initial guesses x0 and x1 such that f(x0)f(x1) < 0

    4. Choose pre-specified tolerable error e.

    5. Calculate new approximated root as x2 = (x0 + x1)/2

    6. Calculate f(x0)f(x2)
	    a. if f(x0)f(x2) < 0 then x0 = x0 and x1 = x2
	    b. if f(x0)f(x2) > 0 then x0 = x2 and x1 = x1
	    c. if f(x0)f(x2) = 0 then goto (8)
	
    7. if |f(x2)| > e then goto (5) otherwise goto (8)

    8. Display x2 as root.

    9. Stop
</details>

<details>
    <summary>False Position Method Algorithm</summary>
    
    1. start

    2. Define function f(x)

    3. Choose initial guesses x0 and x1 such that f(x0)f(x1) < 0

    4. Choose pre-specified tolerable error e.

    5. Calculate new approximated root as: 
    
       x2 = x0 - ((x0-x1) * f(x0))/(f(x0) - f(x1))

    6. Calculate f(x0)f(x2)
    	a. if f(x0)f(x2) < 0 then x0 = x0 and x1 = x2
    	b. if f(x0)f(x2) > 0 then x0 = x2 and x1 = x1
    	c. if f(x0)f(x2) = 0 then goto (8)
    
    7. if |f(x2)|>e then goto (5) otherwise goto (8)

    8. Display x2 as root.

    9. Stop
</details>

<details>
    <summary>Newton Raphson Method Algorithm</summary>

    1. Start

    2. Define function as f(x)

    3. Define first derivative of f(x) as g(x)

    4. Input initial guess (x0), tolerable error (e) 
       and maximum iteration (N)

    5. Initialize iteration counter i = 1

    6. If g(x0) = 0 then print "Mathematical Error" 
       and goto (12) otherwise goto (7) 

    7. Calcualte x1 = x0 - f(x0) / g(x0)

    8. Increment iteration counter i = i + 1

    9. If i >= N then print "Not Convergent" 
       and goto (12) otherwise goto (10) 

    10. If |f(x1)| > e then set x0 = x1 
        and goto (6) otherwise goto (11)

    11. Print root as x1

    12. Stop

</details>