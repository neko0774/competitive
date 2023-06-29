N = int(input())
A = [int(i)%200 for i in input().split()]

dp = [[[] for _ in range(201)] for _ in range(N+1)]
for i in range(N):
  if len(dp[i+1][0])<2: dp[i+1][A[i]].append([i+1])
  for j in range(201):
    if dp[i][j]:
      #print(1, dp[i][j])
      for lis in dp[i][j]:
        if len(dp[i+1][(j+A[i])%200])<2: dp[i+1][(j+A[i])%200].append(lis+[i+1])
        if len(dp[i+1][j])<2: dp[i+1][j].append(lis)
  #print(dp[i+1])
#dp[-1][0].append([])
for i in range(201):
  if len(dp[-1][i])>=2:
    print("Yes")
    print(len(dp[-1][i][0]), *dp[-1][i][0])
    print(len(dp[-1][i][1]), *dp[-1][i][1])
    exit()
print("No")