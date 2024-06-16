from random import randint as ri

n=ri(100,100000)
k=ri(1,n)
print(n,k)
a=[0]*n
for i in range(n):
    a[i]=ri(1,100000)
print(*a)
s=[]
for _ in range(n):
    r=ri(0,10000)
    if r>0:
        s.append('1')
    else:
        s.append('0')
print(''.join(s))