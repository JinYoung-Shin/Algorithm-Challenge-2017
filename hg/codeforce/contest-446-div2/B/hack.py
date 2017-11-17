f = open('input_9.txt', 'w')

n=1000000
val=1000000000

f.write(str(n))
f.write('\n')
for i in range(0, n):
	f.write(str(val) + ' ')

f.close()