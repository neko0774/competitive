N = int(input())
A = [int(i) for i in input().split()]

INF = 10**18
ans = [0, -INF]

for a in A:
  nxt = [0, 0]
  nxt[0] = max(ans[0], ans[1] + a * 2)
  nxt[1] = max(ans[1], ans[0] + a)
  ans = nxt
print(max(ans))