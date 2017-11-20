n, k = map(int, raw_input().split(' '))
S = raw_input()

arr = []
seg_len = 0
for i in S:
    if i == '1':
        if seg_len > 0:
            arr.append(seg_len)
            seg_len = 0
    else:
        seg_len += 1
arr.append(seg_len)

max_seg_len = max(arr)

left_open = False
right_open = False
if S[0] == '0':
    left_open = True
if S[-1] == '0':
    right_open = True
    

ans=0
ans = max(ans, max_seg_len);
if left_open and right_open:
    if len(arr) == 1:
        ans = max(ans, (n*k))
    elif k > 1:
        ans = max(ans, arr[0] + arr[-1])

print ans