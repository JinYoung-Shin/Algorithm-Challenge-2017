S = raw_input()
list = [-1]*26
for i, ch in enumerate(S):
    pos = ord(ch) - ord('a')
    if list[pos] == -1:
        list[pos] = i
    
print " ".join(map(str, list))