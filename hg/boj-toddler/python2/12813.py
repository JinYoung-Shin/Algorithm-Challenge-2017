a=raw_input()
b=raw_input()

#length = 100000
length = len(a)

And=""
Or=""
Xor=""
NotA=""
NotB=""

for i in range(0, length):
	if a[i] == '1' and b[i] == '1':
		And = And + '1'
	else:
		And = And + '0'
	if a[i] == '1' or b[i] == '1':
		Or = Or + '1'
	else:
		Or = Or + '0'
	if a[i] == '1' and b[i] == '0' or a[i] == '0' and b[i] == '1':
		Xor = Xor + '1'
	else:
		Xor = Xor + '0'
	if a[i] == '1':
		NotA = NotA + '0'
	else:
		NotA = NotA + '1'
	if b[i] == '1':
		NotB = NotB + '0'
	else:
		NotB = NotB + '1'
		
print And
print Or
print Xor
print NotA
print NotB