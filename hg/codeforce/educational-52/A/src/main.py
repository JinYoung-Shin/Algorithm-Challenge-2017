tc = int(input())

for i in range(0, tc):
    s,a,b,c = list(map(int, input().split(' ')))
    get = int(s / c);
    extra = int(get / a) * b
    print (get+extra)