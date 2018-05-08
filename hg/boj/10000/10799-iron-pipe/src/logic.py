seq = raw_input()
seq = seq.replace("()", "1")

# print seq

opened = 0
ans = 0
for i in seq:
    if i == '(':
        opened += 1
    elif i == '1':
        ans += opened
    elif i == ')':
        opened -= 1
        ans += 1
        
print ans