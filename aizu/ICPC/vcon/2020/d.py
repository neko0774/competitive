from collections import deque
def count(S):
  cntf = deque([0])
  for s in S:
    if s=='(':
      cntf[-1] += 1
    else:
      if cntf[0]<=2:
        cntf.popleft()
      else:
        cntf[0] -= 2
      if len(cntf)==0 or cntf[-1]!=0:
        cntf.append(0)
  ret = 0
  for c in cntf:
    ret += -(-c//2)
  return ret 

while True:
  S = input()
  if S=='#': exit()
  ans = count(S)
  #print(ans)
  S = S.replace('(', '#').replace(')', '(').replace('#', ')')[::-1]
  #print(S, count(S))
  print(ans+count(S))