def judge(S, T):
  if abs(len(S)-len(T))>1:
    return 0
  if len(S)>len(T):
    S, T = T, S
    #T>S
  if len(S)==len(T):
    cnt = 0
    for i in range(len(S)):
      if S[i]!=T[i]: cnt += 1
    return 1 if cnt<=1 else 0
  N = len(S) 
  #del
  ss = 0
  tt = 0
  cnt = 0
  while ss<len(S) and tt<len(T):
    if S[ss]!=T[tt]:
      tt += 1
      cnt += 1
    else:
      ss += 1
      tt += 1
  if cnt<=1: return 1

N, T = input().split()
N = int(N)
ans = []
for i in range(N):
  S = input()
  if judge(S, T):
    ans.append(i+1)
print(len(ans))
print(*ans)