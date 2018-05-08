a=input()
b=input()
c=input()
val=str(a*b*c)
ans = [0] * 10
for i in val:
	ans[int(i)] += 1
	
for i in range(0, 10):
	print ans[i]