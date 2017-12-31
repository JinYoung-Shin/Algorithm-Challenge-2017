hash={}
n, m = map(int, raw_input().split(' '))

for i in range(0, n):
    str = raw_input()
    hash[str] = False
for i in range(0, m):
    str = raw_input()
    if hash.get(str) != None:
        hash[str] = True
        
out=[]
for key in hash:
    if hash[key] == True:
        out.append(key)
        
out.sort()
print len(out)
for str in out:
    print str