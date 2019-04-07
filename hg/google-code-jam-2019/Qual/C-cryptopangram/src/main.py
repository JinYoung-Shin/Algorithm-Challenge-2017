import copy

def gcd(x,y):
    while(y):
        x,y=y,x%y
    return x
    
def make_unique(l):
    t = []
    for v in l:
        if len(t)==0 or t[-1] != v:
            t.append(v)
    return t
   
tc=int(input())
for t in range(1, tc+1):
    plainValue = [0 for i in range(0, 110)]
    N, L = map(int, input().split(' '))
    ciphers = list(map(int, input().split(' ')))
    primes = []
    int2char = {}
    
    for i in range(0, L-1):
        if ciphers[i] != ciphers[i+1]:
            cd = gcd(ciphers[i], ciphers[i+1])
            primes.append(cd)
            primes.append(ciphers[i]//cd)
            primes.append(ciphers[i+1]//cd)
            
    primes.sort()
    primes = make_unique(primes)
    c = 'A'
    for p in primes:
        if int2char.get(p) == None:
            int2char[p] = c
            c = chr(ord(c) + 1)
            
    idx = 0
    pval = 0
    ppval = 0
    
    for idx in range(0, L-1):
        if ciphers[idx] != ciphers[idx+1]:
            cd = gcd(ciphers[idx], ciphers[idx+1])
            plainValue[idx+1] = cd
            pval = ciphers[idx+1] // cd
            ppval = ciphers[idx] // cd
            break
    
    for i in range(idx, 0, -1):
        plainValue[i] = ppval
        ppval = ciphers[i-1] // ppval
    plainValue[0] = ppval
    
    for i in range(idx+2, L):
        plainValue[i] = pval
        pval = ciphers[i]  // pval
    plainValue[L] = pval
    
    
    ans = ""
    for i in range(0, L+1):
        ans += int2char[plainValue[i]]
    print ("Case #" + str(t) + ": " + ans)