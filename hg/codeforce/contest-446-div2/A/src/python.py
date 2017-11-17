n=input()
a=map(int, raw_input().split(' '))
b=map(int, raw_input().split(' '))

cola=0
b.sort()
for i in a:
	cola += i
	
# print "cola:" + str(cola)
# print b
capacity = b[-1] + b[-2]
# print b[-1]
# print b[-2]
if cola <= capacity:
	print "YES"
else:
	print "NO"