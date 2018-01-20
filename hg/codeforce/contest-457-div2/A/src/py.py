x=input()
hh, mm = map(int, raw_input().split(' '))
def is_lucky():
    if '7' in str(hh) or '7' in str(mm):
        return True
    else:
        return False
# print x
# print hh
# print mm

ans=0

while is_lucky() == False:
    ans+=1
    mm -= x
    if mm < 0:
        mm += 60
        hh-=1
print ans
