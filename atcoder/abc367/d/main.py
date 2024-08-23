from collections import Counter
N, M = map(int, input().split())
A = [int(i) for i in input().split()]

CUM = [0]
for a in A[:-1]:
  CUM.append(CUM[-1] + a)
for i in range(N):
  CUM[i] %= M

C = Counter(CUM)
ans = 0

for i in range(N):
  C[CUM[i]] -= 1
  ans += C[CUM[i]]
  CUM.append(CUM[-1] + A[(N + i - 1) % N])
  CUM[-1] %= M
  C[CUM[-1]] += 1
print(ans)