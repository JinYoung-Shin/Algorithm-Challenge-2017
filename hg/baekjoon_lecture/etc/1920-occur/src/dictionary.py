n=input()
insert_list=map(int, raw_input().split(' '))
hash_map = {}
for i in insert_list:
	hash_map[i] = True
	
m=input()
check_list=map(int, raw_input().split(' '))
for i in check_list:
	if hash_map.get(i) != None:
		print 1
	else:
		print 0