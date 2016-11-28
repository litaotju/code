def fibonacci(n):
    if n<=3:
        return n
    l = [1, 2, 3]
    
    for i in range(3, n):
        l[1] = l[2]    
        l[2] = l[3]
        l[3] = l[1]+l[2]
    return l[3]
