n=input()
arr=[]
for i in range(0, n):
	tmp=input()
	arr.append(tmp)
	
arr.sort()
for i in range(0, n):
	print arr[i]
