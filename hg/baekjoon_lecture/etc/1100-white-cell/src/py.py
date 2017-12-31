ans = 0
for i in range(0, 8):
    line = raw_input()
    for j in range(0, 8):
        if (i+j) % 2 == 0 and line[j] == 'F':
            ans+=1
            
print ans