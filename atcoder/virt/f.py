N, K = map(int, input().split())
V = [int(i) for i in input().split()]

ans = 0
for l in range(N + 1):
  for r in range(l, N + 1):
    k = K - (l + N - r)
    #print(l, r, k)
    if k < 0: continue
    gem = []
    value = 0
    for i in range(l):
      gem.append(V[i])
      value += V[i]
    for i in range(r, N):
      gem.append(V[i])
      value += V[i]
    gem.sort()
    for g in gem[:k]:
      if g < 0:
        value -= g
    ans = max(ans, value)
print(ans)