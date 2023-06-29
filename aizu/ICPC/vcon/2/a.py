def solve(S):
  count = set()
  for i in range(len(S)):
    f, b = S[:i], S[i:]
    for ff, bb in [[f, b], [b, f]]:
      count.add(ff+bb)
      count.add(ff[::-1]+bb)
      count.add(ff+bb[::-1])
      count.add(ff[::-1]+bb[::-1])
  return len(count)
N = int(input())
for _ in range(N):
  S = input()
  print(solve(S))