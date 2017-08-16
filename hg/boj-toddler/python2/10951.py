while True:
	str=raw_input()
	if len(str) < 1:
		break
	a=int(str.split(' ')[0])
	b=int(str.split(' ')[1])
	print a+b
	