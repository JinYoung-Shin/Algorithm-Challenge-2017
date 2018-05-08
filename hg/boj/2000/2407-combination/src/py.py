n, m = map(int, raw_input().split(' '))
ans = 1
for u in range(n-m+1, n+1):
	ans *= u
	
for d in range(2, m+1):
	ans /= d
	
print ans