S = input()
mod = 998244353
dp = [[0 for _ in range(len(S)+1)] for _ in range(len(S)+1)]
dp[0][0] = 1
for n, s in enumerate(S):
  for cnt in range(n+2):
    if s=="(":
      if cnt>0: dp[n+1][cnt] = dp[n][cnt-1]
    elif s==")":
      if cnt+1<len(S): dp[n+1][cnt] = dp[n][cnt+1]
    else:
      if cnt+1<len(S): dp[n+1][cnt] += dp[n][cnt+1]
      if cnt>0: dp[n+1][cnt] += dp[n][cnt-1]
    dp[n+1][cnt] %= mod
print(dp[-1][0])
