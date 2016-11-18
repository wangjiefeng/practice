def stamps(N):
    # Your code here
    n = 1
    while (5*n) < N:
        n = n+1
    s = 5*(n-1)
    if s == N:
        five = n-1
        two = 0
        one = 0
    else:
        if n == 1:
            five = 0
        N = N - 5*(n-1)
        n = 1
        while (2*n) < N:
            n = n+1
        s = 2*(n-1)
        if s == N:
            two = n-1
            one = 0
        else:
            N = N - 2*(n-1)
            n = 1
            while n != N:
                n = n+1
            one = n
    anwser = '('+ str(five) + str(two) + str(one) + ')'
    return  anwser