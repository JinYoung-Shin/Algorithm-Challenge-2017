k, mod = map(int, raw_input().split(' '))

def pal(val):
    a=str(val)
    b=a[::-1]
    return int(a+b)

ans=0
for i in range(1, k+1):
    # print i
    # print pal(i)
    addition = pal(i) % mod
    ans += addition
    ans %= mod
print ans
