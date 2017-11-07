n, x = map(int, raw_input().split(' '))

arr = raw_input().split(' ')
output = ""
for a in arr:
	if int(a) < x:
		output += a
		output += ' '
print (output)
