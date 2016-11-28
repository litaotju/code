def sqrt(x):
    # write your code here
    a = 0
    b = x
    m = 0
    while(a!=b):
        m = (a+b)/2
        if m**2 > x:
            b = m+1
        elif m**2 == x:
            return m
        else:
            a = m
        print "a:%d b:%d m>:%d" %(a, b, m)
    return m

print sqrt(10)
