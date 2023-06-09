N, P, Q, R, S = map(int, input().split())
A = [int(i) for i in input().split()]
P -= 1
R -=1
A[P:Q], A[R:S] = A[R:S], A[P:Q]
print(*A)