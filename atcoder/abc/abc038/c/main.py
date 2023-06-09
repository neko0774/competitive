N = int(input())
A = [int(i) for i in input().split()]

from collections import deque

ans = 0
q = deque()
for a in A:
    q.append(a)
    while len(q)>=2 and (q[0]>=q[1] or q[-1]<=q[-2]):
        q.popleft()
    ans += len(q)
print(ans)