import sys

n=input()
def beat(i):
    rhs=2**(i-1)
    lhs=rhs*2-1
    return rhs*lhs

i = 10
while i >= 1:
    if n % beat(i) == 0:
        print beat(i)
        sys.exit()
    else:
        i -= 1