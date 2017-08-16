import collections

d = collections.deque()

n=input()
for i in range(0, n):
	cmd=raw_input()
	if "push_front" in cmd:
		val=int(cmd.split(' ')[1])
		d.appendleft(val);
	elif "push_back" in cmd:
		val=int(cmd.split(' ')[1])
		d.append(val);
	elif "pop_front" in cmd:
		if len(d) == 0:
			print -1
		else:
			print d.popleft()
	elif "pop_back" in cmd:
		if len(d) == 0:
			print -1
		else:
			print d.pop()
	elif "size" in cmd:
		print len(d)
	elif "empty" in cmd:
		if len(d) == 0:
			print 1
		else:
			print 0
	elif "front" in cmd:
		if len(d) == 0:
			print -1
		else:
			print d[0]
	elif "back" in cmd:
		if len(d) == 0:
			print -1
		else:
			idx=len(d)-1
			print d[idx]
	