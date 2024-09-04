from bisect import bisect_left as bl
def solve():
  N, M = map(int, input().split())
  K = [0] * N
  for i in range(N):
    K[i] = int(input())
  K.sort()
  for i in range(M):
    a, b, c = map(int, input().split())

    v = bl(K, b)
    mi = K[max(v - 1, 0)]
    ma = K[min(v, N - 1)]

    if (b - ma) ** 2 - 4 * a * c < 0:
      print("Yes")
      print(ma)
    elif (b - mi) ** 2 - 4 * a * c < 0:
      print("Yes")
      print(mi)
    else:
      print("No") 

n = int(input())
for _ in range(n):
  solve()