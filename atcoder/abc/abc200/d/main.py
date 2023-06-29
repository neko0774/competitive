N = int(input())
A = [int(i)%200 for i in input().split()]

dp = [[0 for _ in range(201)] for _ in range(N+1)]
dp[0][0] = 1
for j, a in enumerate(A):
  ndp = [0 for _ in range(201)]
  for n in range(201):
    dp[j+1][(n+a)%200] = dp[j][n]
  for i in range(201):
    dp[j+1][i] += dp[j][i]
dp[-1][0] -= 1
if max(dp[-1])<=1:
  print("No")
  exit()

for i in ragne(201):
  if dp[-1][i]>=2:
    break


for n in range(N)[::-1]: