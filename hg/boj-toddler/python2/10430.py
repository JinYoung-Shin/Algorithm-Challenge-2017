raw=raw_input().split(' ')
A=int(raw[0])
B=int(raw[1])
C=int(raw[2])

print (A+B)%C
print (A%C + B%C)%C
print (A*B)%C
print (A%C * B%C)%C