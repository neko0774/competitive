mod = 10
def solve():
  N, M, K = map(int, input().split())
  if M-K == 1:
    if N>=K: return 0
    else: return 
  N %= (M-K)
  print(N, M)
  return pow(2, N, mod)


T = int(input())
for _ in range(T):
  print(solve())