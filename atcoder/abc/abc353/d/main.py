mod = 998244353
N = int(input())
A = [int(i) for i in input().split()]

ans = 0
from collections import defaultdict
count = defaultdict(int)
for a in A:
  count[len(str(a))] += 1
  

for i, a in enumerate(A):
  count[len(str(a))] -= 1
  if count[len(str(a))] == 0: count.pop(len(str(a)))
  for v, n in count.items():
    ans += a*pow(10, v, mod)%mod*n
    ans %= mod
  A[i] %= mod
S = sum(A)
for a in A:
  S -= a
  ans += S
  ans %= mod

print(ans%mod)

