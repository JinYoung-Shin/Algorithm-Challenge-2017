import sys

asdf={'black':'0','brown':'1','red':'2','orange':'3','yellow': '4', 'green': '5', 'blue': '6', 'violet': '7', 'grey': '8', 'white': '9'}


output = ""
a=raw_input()

output += asdf[a]
a=raw_input()

output += asdf[a]
a=raw_input()

num=int(asdf[a])
output += '0' * num

print int(output)
