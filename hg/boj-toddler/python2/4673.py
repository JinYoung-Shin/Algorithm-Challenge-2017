def val(n):
	s=str(n)
	l=len(s)
	ret=0
	for i in range(0, l):
		ret = ret + int(s[i])
	return ret
def d(n):
	ret=n+val(n)
	return ret

dic = {}
for i in range(1, 10001):
	idx=d(i)
	dic[idx] = True

for i in range(1, 10001):
	if dic.get(i) == None:
		print (i)
