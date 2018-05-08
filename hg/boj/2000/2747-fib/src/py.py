n=input()

a=1
b=1

if n is 1 or n is 2:
    print 1
elif n >= 3:
    for i in range(2, n):
        c=a+b
        a=b
        b=c
    print c