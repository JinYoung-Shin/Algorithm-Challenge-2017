import sys

dp = [-1] * 251
def get(i):
    if i <= 0:
        return 1
    if i == 1:
        return 1
    if dp[i] != -1:
        return dp[i]
    ret = get(i-1) + 2*get(i-2)
    dp[i] = ret
    return ret
while True:
    line = sys.stdin.readline()
    if len(line) != 0:
        n = int(line)
        print get(n)
    else:
        sys.exit()