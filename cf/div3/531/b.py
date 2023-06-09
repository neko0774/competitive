from collections import Counter, defaultdict
N, K = map(int, input().split())
A = [int(i) for i in input().split()]
C = Counter(A)

mx = max(C.values())
sm = sum(C.values())
if mx>K or sm<K:
    print("NO")
else:
    print("YES")
    colour = dict()
    c = 0
    for k,v in C.items():
        colour[k] = c
        c += v
        c %= K
    ans = []
    for a in A:
        c = colour[a]%K+1
        ans.append(c)
        colour[a] += 1
    print(*ans)
