N, M = map(int, input().split())
from collections import deque
A = deque([int(i) for i in input().split()])
ans = []
memo = []
for i in range(1, N+1):
    if A and A[0]==i:
        memo.append(i)
        A.popleft()
    else:
        ans.append(i)
        ans += memo[::-1]
        memo = []
    i += 1
ans += memo[::-1]
print(*ans)