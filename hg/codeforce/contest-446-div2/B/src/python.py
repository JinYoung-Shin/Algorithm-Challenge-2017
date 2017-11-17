n=input()
arr=map(int, raw_input().split(' '))

live_num=0
dead_left=0
for i in range(1, n+1):
	if dead_left >0:
		dead_left-=1
	else:
		live_num+=1
	dead_left=max(dead_left, arr[-i])
print live_num