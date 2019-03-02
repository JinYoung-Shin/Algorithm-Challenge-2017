import sys

n, m = map(int, raw_input().split(' '))
data = {}
for i in range(0, n):
    name, ipaddr = raw_input().split(' ')
    data[ipaddr] = name
# print data
for i in range(0, m):
    cmd, ip = raw_input().split(' ')
    ipkey = ip[:-1]
    comment = "#" + data[ipkey]
    print cmd + " " + ip + " " + comment