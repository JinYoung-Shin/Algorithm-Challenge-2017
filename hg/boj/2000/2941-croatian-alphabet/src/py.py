s=raw_input()
list=["c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="]
for pat in list:
    s= s.replace(pat, "0")
print len(s)