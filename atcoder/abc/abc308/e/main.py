N = int(input())
A = [int(i) for i in input().split()]
S = [i for i in input()]

countM = [[0, 0, 0] for _ in range(N+1)]
countX = [[0, 0, 0] for _ in range(N+1)]
posE = []
for n, s in enumerate(S):
  if s=='E': posE.append(n)
  elif s=='M': countM[n+1][A[n]] += 1
  else: countX[n+1][A[n]] += 1

for n in range(1, N+1):
  for i in range(3):
    countM[n][i] += countM[n-1][i]
    countX[n][i] += countX[n-1][i]
def mex(lis):
  for i in range(4):
    if i not in lis: return i
  

def count(a, E, X):
  ret = 0
  for i in range(3):
    if E[i]==0: continue
    for j in range(3):
      ret += mex(set([a, i, j]))*E[i]*X[j]
  return ret

ans = 0
for n in posE:
  M = []
  X = []
  for i in range(3):
    M.append(countM[n+1][i]-countM[0][i])
    X.append(countX[-1][i]-countX[n+1][i])
  #print(A[n], M, X, count(A[n], M, X))
  ans += count(A[n], M, X) 
print(ans)