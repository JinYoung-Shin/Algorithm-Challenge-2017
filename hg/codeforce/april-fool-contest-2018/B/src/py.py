import sys

normal_only = ["not bad\n","great\n", "don't touch me\n", "don't think so\n", "cool\n"]
grumpy_only = ["don't even\n", "terrible\n", "worse\n", "no way\n", "go die in a hole\n", "are you serious\n"]
def query(a):
    print (str(a), flush=True)
    # res = input()
    res = sys.stdin.readline()
    return res
    
for i in range(0, 10):
    res = query(i)
    if res in normal_only:
        print ("normal", flush=True)
        sys.exit()
    elif res in grumpy_only:
        print ("grumpy", flush=True)
        sys.exit()