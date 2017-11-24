for i in range(0, 3):
	arr = raw_input().split(' ')
	cnt=0
	for j in arr:
		if j == '1':
			cnt+=1
	if cnt == 1:
		print "C"
	elif cnt == 2:
		print "B"
	elif cnt == 3:
		print "A"
	elif cnt == 0:
		print "D"
	elif cnt == 4:
		print "E"
	