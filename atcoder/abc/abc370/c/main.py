S = [i for i in input()]
T = [i for i in input()]
N = len(S)
ans = 0
for i in range(N):
  if S[i] != T[i]:
    ans += 1
print(ans)
for j in range(ans):
  is_changed = 0
  for i in range(N):
    if S[i] != T[i] and T[i] < S[i]:
      is_changed = 1
      S[i] = T[i]
      break
  if is_changed:
    print("".join(S))
    continue
  
  for i in range(N)[::-1]:
    if S[i] != T[i]:
      S[i] = T[i]
      break
  print("".join(S))