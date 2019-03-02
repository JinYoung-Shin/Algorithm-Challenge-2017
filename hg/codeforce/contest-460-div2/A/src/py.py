n, k = map(int, raw_input().split(' '))
price = float(987654321)
aa=111
bb=111

for i in range(0, n):
    a, b = map(int, raw_input().split(' '))
    if price > (float(a)/b):
        price = (float(a)/b)
        aa = a
        bb = b
ans = float(aa*k)/bb

print ans