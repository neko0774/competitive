N, X = map(int, input().split())
A = [int(i) for i in input().split()]

ans = 0

for i in range(1, N):
    if A[i-1]+A[i]>X:
        subt = A[i-1]+A[i]-X
        ans += subt
        A[i] = max(0, A[i]-subt)
print(ans)