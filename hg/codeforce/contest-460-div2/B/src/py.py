def get(string):
    ret=0
    string = str(string)
    for i in string:
        ret += int(i)
    return ret
    
k = input()

def get_kth_prefix(k):
    prefix=1
    for i in range(1, k):
        prefix+=1
        while get(str(prefix)) > 10:
            prefix+=1
    return prefix
        


# for i in range(1, k+1):
#     prefix = get_kth_prefix(i)
#     ans = str(prefix) + str(10-get(prefix))
#     print str(i) + " : " + ans
    
    
prefix = get_kth_prefix(k)
ans = str(prefix) + str(10-get(prefix))
print ans