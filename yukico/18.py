N = int(input())
NN = N

i = 2
ret = []
while i*i<=N:
    c = [i, 0]
    while N%i==0:
        c[1] += 1
        N //= i
    if c[1]>0:
        ret.append(c)
    i += 1
if N!=1: ret.append([N, 1])

num = 0
for _, n in ret:
    num ^= n
print("Alice" if num!=0 else "Bob")