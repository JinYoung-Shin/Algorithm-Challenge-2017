import sys

t = input()

def facto(n):
    ret=1
    for i in range(2, n+1):
        ret *= i
    return ret
def bicof(n, r):
    ret = 1
    for i in range(n-r+1, n+1):
        ret *= i
    ret /= facto(r)
    return ret
    
for i in range(0, t):
    a, b = map(int, raw_input().split(' '))
    if a < b:
        a, b = b, a #swap

    print bicof(a, b)