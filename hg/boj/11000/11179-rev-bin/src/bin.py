n=input()

binary_string=str(bin(n))[2:]
reversed_binary_string = binary_string[::-1]
answer=int(reversed_binary_string, 2)
print answer