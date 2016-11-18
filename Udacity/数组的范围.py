def bigger(a,b):
    if a>b:
        return a
    else:
        return b

def smaller(a,b):
    if a<b:
        return a
    else:
        return b

def biggest(a,b,c):
    if a>bigger(b,c):
        return a
    else:
        return bigger(b,c) 

def smallest(a,b,c):
    if a<smaller(b,c):
        return a
    else:
        return smaller(b,c)


def set_range(a,b,c):
    # Your code here
    x = biggest(a,b,c)
    y = smallest(a,b,c)
    return x-y