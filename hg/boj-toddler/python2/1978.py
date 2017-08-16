n=input()
num_arr=raw_input().split(' ')
ans=0
def is_prime(k):
	if k == 1:
		return False
	for i in range(2, k):
		if k % i == 0:
			return False
	return True	
	
for i in range(0, n):
	cur=int(num_arr[i])
	if is_prime(cur) == True:
		ans = ans + 1

print ans