N, X = map(int, input().split())
ans = 0
L = [[int(i) for i in input().split()] for _ in range(N)]
import pypyjit
pypyjit.set_param('max_unroll_recursion=-1')
def dfs(x, cur=0):
    global ans
    if cur==N:
        if x==X: ans += 1
        return
    for num in L[cur][1:]:
        if not x*num>X: dfs(x*num, cur+1)
dfs(1)
print(ans)