def is_han(n):
	s=str(n)
	l=len(s)
	if l == 1:
		return True
	inc=int(s[1]) - int(s[0])
	for i in range(1, l-1):
		if int(s[i+1]) - int(s[i]) != inc:
			return False
	return True

val=0
n=input()
for i in range(1, n+1):
	if is_han(i) == True:
		val = val + 1
		
print (val)