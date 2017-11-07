n = input()
arr = map(int, raw_input().split(' '))
max_val = max(arr)
def average(values):
	if len(values) == 0:
		return None
	return sum(values, 0.0) / len(values)
average_val = average(arr)

average_val /= max_val
average_val *= 100
print ("%.2f" % average_val)