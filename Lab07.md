# Newton Forward Difference

## Algorithm

    1. Start

    2. Read number of data points, say n.

    3. Read the value at which interpolated value is needed, say xp.

    4. Read n data points, say x[i] and fx[i].

    5. Set h = x[1] - x[0] and s = (xp - x[0]) / h.

    6. Calculate first forward difference as below,

        For i = 0 to n - 1
            fd[i] = fx[i]
        End for

    7. Calculate second to nth forward difference as below,
        
        For i = 0 to n - 1
            For j = n - 1 to i + 1
                fd[j] = fd[j] - fd[j - 1]
            End For
        End For

    8. Set v = fd[0] and Set p = 1.

    9. Calculat interpolated value as below,

        For i = 1 to n - 1
            For k = 1 to i
                p = p * (s - k + 1)
            End For
            v = v + (fd[i] * p) / i!
            Reset p = 1
        End For
    
    10. Print the interpolated value v at xp.

    11. Terminate.