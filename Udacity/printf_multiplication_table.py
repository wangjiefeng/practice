def print_multiplication_table(n):
    x=1
    y=1
    while (x < n):
        while (y < n):
            print(y + " * " + x + " = " + x * y)
            y = y+1
        x = x + 1