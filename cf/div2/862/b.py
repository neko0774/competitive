def solve():
  N = int(input())
  S = input()
  l = 'z'
  for s in S:
    l = min(s, l)
  for i in range(N)[::-1]:
    if S[i] == l:
      ans = S[i] + S[:i] + S[i + 1:]
      print(ans)
      return

n = int(input())
for _ in range(n):
  solve()