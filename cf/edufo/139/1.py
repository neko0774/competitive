count = [0]*10**6
def is_good(x):
    cnt = 0
    for i in x:
        if i!="0": cnt += 1
    return 1 if cnt==1 else 0
for i in range(10**6):
    count[i] += is_good(str(i))
for i in range(1, 10**6):
    count[i] += count[i-1]

T = int(input())
for _ in range(T):
    x = int(input())
    print(count[x])