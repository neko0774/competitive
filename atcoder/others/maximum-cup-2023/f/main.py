
def solve(N, M, K, S):
  segment = '1'*S+'0'*(K-S)
  #repeating segment
  times = (N+M)//len(segment)
  #繰り返される回数
  remind = N+M-K*times

  MM = M-S*times
  #number of 1 needed
  NN = N-times*(K-S)
  #print(NN, MM)
  head = '0'*NN
  tail = '1'*MM
  body = segment*times
  ans = head+body+tail
  if N<0 or MM<0:
    print("No")
    return 

  cnt_zero = K-S
  def is_valid(SS):
    cnt = 0
    #print(SS)
    for s in SS[:K]:
      if s=='0': cnt+=1
    #print(cnt)
    if cnt!=cnt_zero: return False
    for i in range(N+M-K):
      if SS[i+K]=="0": cnt += 1
      if SS[i]=="0": cnt -= 1
      if cnt!=cnt_zero: return False

    cnt = 0
    for s in SS:
      if s=='0': cnt+=1
    return cnt==N


  if is_valid(ans):
    print("Yes")
    print(ans)
  else:
    print("No")


import random as rd


#for i in range(100):
#  N = rd.randint(1, 100)
#  M = rd.randint(1, 100)
#  K = rd.randint(1, N+M)
#  S = rd.randint(1, K)
#  print(N, M, K, S)
#  solve(N, M, K, S)
N, M, K, S = map(int, input().split())
solve(N, M, K, S)