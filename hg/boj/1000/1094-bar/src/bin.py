a= input()
b=bin(a)
ans=0
for i in b:
    if i == '1':
        ans+=1
        
print ans