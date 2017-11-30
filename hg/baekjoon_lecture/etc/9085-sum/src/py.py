tc=input()
for i in range(0, tc):
    nn=input()
    out=0
    ll = map(int, raw_input().split(' '))
    for j in ll:
        out += j
    print out