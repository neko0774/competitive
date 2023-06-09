from heapq import heappop, heappush
N, K = map(int, input().split())
items = []
for _ in range(N):
    a,b = map(int, input().split())
    heappush(items, (a, b))
ans = 0
for _ in range(K):
    a,b = heappop(items)
    ans += a
    heappush(items, (a+b, b))
print(ans)