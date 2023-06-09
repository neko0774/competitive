DD = int(input())
N = int(input())
M = int(input())
D = [0]+[int(input()) for _ in range(N-1)]+[DD]
K = [int(input()) for _ in range(M)]
D.sort()
from bisect import bisect_left as bl
ans = 0
for k in K:
    i = bl(D, k)
    ans += min(abs(k-D[i]), abs(k-D[i-1]))
print(ans)