str=raw_input().split(' ')
x=int(str[0])
y=int(str[1])

#print x
#print y

day=0
for i in range(1, x):
	if i==1 or i==3 or i==5 or i==7 or i==8 or i==10 or i==12:
		day=day+31
	elif i==4 or i==6 or i==9 or i==11:
		day=day+30
	else:
		day=day+28
		
day=day+y
day = day % 7

#print day
if day==1:
	print "MON"
elif day==2:
	print "TUE"
elif day==3:
	print "WED"
elif day==4:
	print 'THU'
elif day==5:
	print 'FRI'
elif day==6:
	print 'SAT'
else:
	print 'SUN'