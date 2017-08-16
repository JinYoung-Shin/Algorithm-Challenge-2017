n=input()
num_arr=raw_input().split(' ')
num_set=set()
for i in range(0, n):
	num_set.add(int(num_arr[i]));
	
num_list=list(num_set)
num_list.sort()
length=len(num_list)
for i in range(0, length):
	print num_list[i], 