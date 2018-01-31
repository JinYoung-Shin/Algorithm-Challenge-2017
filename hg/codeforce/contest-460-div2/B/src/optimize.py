def get(string):
    ret=0
    string = str(string)
    for i in string:
        ret += int(i)
    return ret
    
k = input()

def make_next(val):
	string = str(val)
	idx = len(string) - 1
	while idx >= 0 and string[idx] == "0":
		idx -= 1
	addition = 10**(len(string) - idx)
	val += addition
	val -= (val %addition)
	return val
        

def get_kth_prefix(k):
    prefix=1
    for i in range(1, k):
        if get(prefix) == 10:
            prefix = make_next(prefix)
        else:
            prefix+=1
    return prefix
        

prefix = get_kth_prefix(k)
ans = str(prefix) + str(10-get(prefix))
print ans