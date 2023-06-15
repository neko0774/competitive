N = int(input())
V = []
G = [[] for _ in range(N)]
for n in range(N):
    x, y, z = map(int, input().split())
    V.append([max(x, y, z), x+y+z-max(x,y,z)-min(x,y,z), min(x,y,z), x*y*z])
import itertools as it
ans = 10**18
def ok(B, A):
    return A[0]>B[0] and A[1]>B[1] and A[2]>B[2]
for ite in it.permutations(range(N)):
    memo = V[ite[0]][-1]
    for i in ite[1:]:
        if not ok(V[i], V[i-1]):
            memo += V[i][-1]
    print(memo, ans)
    ans = min(ans, memo)
print(ans)
