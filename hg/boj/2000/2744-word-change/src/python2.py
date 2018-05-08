import sys

ss=raw_input()
for a in ss:
	if a.islower():
		sys.stdout.write(a.upper())
	else:
		sys.stdout.write(a.lower())