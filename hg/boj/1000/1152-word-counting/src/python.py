aa = raw_input()
cnt = 0
wordFound = False
for i in aa:
	if i == ' ':
		wordFound = False
	elif wordFound == False:
		cnt += 1
		wordFound = True
print cnt