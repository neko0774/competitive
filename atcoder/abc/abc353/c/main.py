from bisect import bisect_left as bl
N = int(input())
A = [int(i) for i in input().split()]
A.sort()
ans = 0
mod = 10**8
S = sum(A)
for i, a in enumerate(A):
  S -= a
  idx = bl(A, mod-a)
  ans += a*(N-i-1) + S
  ans -= mod * min(N-i-1, N-idx)
print(ans)