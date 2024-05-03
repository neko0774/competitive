import random

n=10**5
print(n)
p=[0]*n
for i in range(n):p[i]=i+1
random.shuffle(p)
print(*p)
print(0)