N = int(input())
S = [int(input()) for _ in range(N)]

ans = 0
count = [0] * N
for i in range(N):
  for j in range(N):
    if i == j: continue
    if S[i] % S[j] == 0:
      count[i] += 1

inv = [0] * N


for cnt in count:
  for i in range(1, cnt + 1, 2):
    ans += 