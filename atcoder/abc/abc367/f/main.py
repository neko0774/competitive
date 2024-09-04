from random import randint as rd
N, Q = map(int, input().split())
A = [int(i) - 1 for i in input().split()]
B = [int(i) - 1 for i in input().split()]


mod = 10 ** 18
ok = 0
while not ok:
  conv = [rd(1, mod) for _ in range(N)]
  if len(set(conv)) == N: ok = 1


cumA = [0]
cumB = [0]

for a in A:
  cumA.append(cumA[-1] + conv[a])
  cumA[-1] %= mod

for b in B:
  cumB.append(cumB[-1] + conv[b])
  cumB[-1] %= mod

for i in range(Q):
  l, r, L, R = map(int, input().split())
  if r - l != R - L:
    print("No")
  elif (cumA[r] - cumA[l - 1]) % mod == (cumB[R] - cumB[L - 1]) % mod:
    print("Yes")
  else:
    print("No")
