n, k, M, D = map(int, raw_input().split(' '))
ans = 0;
for d in range(1, D+1):
    maxX = M
    maxX = min( n / (k*(d-1) + 1), maxX);    

    if maxX == 0:
        continue
    
    realD = (n/maxX + k - 1) / k
        
    if realD != d:
        continue
        
    ans = max(ans, d * maxX)
    
print ans
