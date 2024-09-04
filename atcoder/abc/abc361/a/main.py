N, K, X = map(int, input().split())
A = [int(i) for i in input().split()]

ans = A[:K] + [X] + A[K:]
print(*ans)