S = [int(i) for i in input().split()]
N = int(input())
ans = []
for i in range(N):
  l, r = map(int, input().split())
  l -= 1
  r -= 1
  S[l], S[r] = S[r], S[l]
  print(" ".join(map(str, S)))
  print(l, r, '|', S[r], S[l])