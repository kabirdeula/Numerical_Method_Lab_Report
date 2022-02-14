# Newton Backward Difference

## Algorithm

    1. Start

    2. Read number of points, say n.
    
    3. Enter the value at which interpolated value is required, say xp.

    4. Read n data points.

    5. Set h = x[1] - x[0] and s = (xp - x[n - 1]) / h.

    6. Calculate first backward difference as below,

        For i = 0 to n - 1
            bd[i] = fx[i]
        End For

    7. Calculate 2nd to nth backward differences as below,

        For i = n - 1 to 1
            For j = 0 to i - 1
                bd[j] = bd[j + 1] - bd[j]
            End For
            Set v = bd[n - 1]
        End For
    
    8. Calculate interpolated value as below,

        For i = 1 to n - 1
            For k = 1 to i
                p = p * (s + k - 1)
            End For
            v = v + (bd[n - i - 1] * p)/ fact(i)
            Reset p = 1
        End For
    
    9. Print interpolated value v at xp

    10. Stop