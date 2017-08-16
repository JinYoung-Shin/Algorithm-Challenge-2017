arr=[0,1,1]

n=input()
if n < len(arr):
	print arr[n]
else:
	for i in range(1, n+1):
		val=arr[i] + arr[i+1]
		arr.append(val)
	print arr[n]