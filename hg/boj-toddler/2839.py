import sys
total=input()

num_5=total/5
rest=total-num_5*5

while num_5>=0 and rest >= 0:
	if rest%3 == 0:
		print num_5 + rest/3
		sys.exit()
	num_5=num_5-1
	rest=total-num_5*5
	
print -1