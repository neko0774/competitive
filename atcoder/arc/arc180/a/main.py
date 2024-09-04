N = int(input())
S = input()
ans = []
cur = 1
i = 0
mod = 10**9+7
while i < N:
  #print(i, cur, ans, S[i:i+3])
  if i+2 < N and S[i:i+3] == 'ABA' or S[i:i+3] == 'BAB':
    i += 2
    cur += 1
  else:
    if cur > 1: ans.append(cur)
    cur = 1
    i += 1
r = 1
for a in ans:
  r *= a
  r %= mod
print(r)