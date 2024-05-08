N = int(input())
S = []
H = 0
for _ in range(N):
  a, b = map(int, input().split())
  S.append([a, b])
  H += a

ans = 0
for a, b in S:
  ans = max(ans, H-a+b)
print(ans)