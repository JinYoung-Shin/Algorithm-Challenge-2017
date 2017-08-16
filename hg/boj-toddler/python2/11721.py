seq=raw_input()

start=0
end=len(seq)
while start<end:
	if start+10 < end:
		print seq[start:start+10]
	else:
		print seq[start:]
	start=start+10