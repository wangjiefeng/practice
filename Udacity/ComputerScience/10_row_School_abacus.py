l = ['|00000*****   |','|00000****   *|','|00000***   **|','|00000**   ***|','|00000*   ****|','|00000   *****|','|0000   0*****|','|000   00*****|','|00   000*****|','|0   0000*****|']
def print_abacus(value):
    d = 1000000000
    while d != 0:
        print(l[int(value/d)])
        value = value % d
        d = int(d/10)