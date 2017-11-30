t=input()
for i in range(0, t):
    r, string = raw_input().split(' ')
    r = int(r)
    out=""
    for ch in string:
        out += ch*r
    print out