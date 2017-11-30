def compress(s):
    state=""
    out=""
    for c in s:
        if state != c:
            out += state
            state = c
    out += state
    return out

def chk(s):
    list=[False]*26
    s=compress(s)
    for c in s:
        pos = ord(c) - ord('a')
        if list[pos] == False:
            list[pos] = True
        else:
            return 0
    return 1
n = input()
ans=0
for i in range(0, n):
    s=raw_input()
    ans += chk(s)
    
print ans