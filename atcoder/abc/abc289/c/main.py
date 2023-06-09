import itertools as it
N, M = map(int, input().split())
A = [[] for _ in range(M)]
for j in range(M):
    _ = int(input())
    A[j] = set(int(i) for i in input().split())

def count(x):
    for i in range(1, N+1):
        if not i in x: return 0
    return 1


ans = 0
for ii in it.product([0, 1], repeat=M):
    memo = set()
    for  n, j in enumerate(ii):
        if j: memo |= A[n]
    ans += count(memo)
print(ans)