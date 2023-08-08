N, M = map(int, input().split())
A = [int(i) for i in input().split()]
size = [0, 2, 5, 5, 4, 5, 6, 3, 7, 6]

dp = [dict() for _ in range(N+1)]

for i in range(N):L