S = [i for i in input()]
T = [i for i in input()]


ans = []
s = 0
for n, t in enumerate(T):
  if t == S[s]:
    ans.append(n+1)
    s += 1
print(*ans)