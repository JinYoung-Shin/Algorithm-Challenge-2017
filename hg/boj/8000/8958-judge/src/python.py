t=input()

def judge(seq):
	ret=0
	accu=0
	for i in seq:
		if i == 'O':
			accu +=1
			ret += accu
		else:
			accu=0
	return ret
for i in range(0, t):
	seq=raw_input()
	print judge(seq)