N = int(input())
A = list(map(int, input().split()))
B = [0]
for i in range(N):B.append(B[-1]+A[i//2])
dp = [0]*(N+1)
for i in range(1, N+1):dp[i]=max([dp[j]+B[i-j-1] for j in range(i)])
print(dp[-1])