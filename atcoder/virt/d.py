S = [i for i in input()]
N = int(input())
for _ in range(N):
  l, r = map(int, input().split())
  l -= 1
  m = S[:]
  for i in range(r - l):
    S[l + i] = m[r - i - 1]
print("".join(S))