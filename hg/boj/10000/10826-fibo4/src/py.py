n=input()

a=0
b=1

if n == 0:
    print 0
elif n == 1:
    print 1
else:
    for i in range(2, n+1):
        next = a+b
        a=b
        b=next
    print b