s=raw_input().lower()
list = [0]*26

for ch in s:
    pos = ord(ch) - ord('a')
    list[pos] += 1
max_val = max(list)
cc=-1
for i, val in enumerate(list):
    if val == max_val:
        if cc == -1:
            cc = chr(ord('A') + i)
        else:
            cc = "?"
            break
print cc
