#!/usr/bin/env python
f = open("input.4.txt", "w")

f.write("100000 99999\n")

for i in range(0, 100000):
    f.write("1000000000 ")
f.write('\n')
for i in range(1, 1000000):
    f.write(str(i) + " " + str(i+1) + "\n")
f.close()