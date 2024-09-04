N, K = map(int, input().split())
A = [int(i) for i in input().split()]
ans = A[-K:] + A[:-K]
print(*ans)