N = int(input())
ppl = []
mn_age = 10**12
num = - 1
for n in range(N):
    s, a = input().split()
    a = int(a)
    ppl.append([s, a])
    if a<mn_age:
        mn_age = a
        num = n

for i in range(N):
    n = (i+num)%N
    print(ppl[n][0])
