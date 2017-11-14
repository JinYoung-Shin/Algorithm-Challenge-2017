a,b,c = map(int, raw_input().split())
a %= c

def bin_split(a, b):
	if b <= 0:
		return 1
	if b == 1:
		return a
	half = bin_split(a, b/2)
	ret = half * half % c
	if b % 2:
		ret = ret * a % c
	return ret
	
print bin_split(a, b)