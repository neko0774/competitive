M, K = map(int, input().split())
N = pow(2, M)
def xor(ary):
  ret = 0
  for a in ary:
    ret ^= a
  return ret
if K==0 and M==1:
  print(0, 0, 1, 1)
elif K>=N or (M==1 and K==1):
  print(-1)
else:
  A = [i for i in range(K)] + [i for i in range(K+1, N)]
  if xor(A)==K:
    print(*A,K,*A[::-1],K)
  else:
    print(-1)
