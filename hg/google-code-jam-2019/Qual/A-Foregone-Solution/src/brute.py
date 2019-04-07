tc=int(input())

def solve(n):
    a=int(str(n).replace('4', '3'))
    b=n-a
    return str(a) + " " + str(b)
for t in range(1, tc+1):
    n=int(input())
    ans=solve(n)
    print ("Case #" + str(t) + ": " + ans)