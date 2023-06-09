import sys
sys.setrecursionlimit(10**6)
N = int(input())
S = [[input(), i] for i in range(N)]
ans = [0]*N
import pypyjit
pypyjit.set_param('max_unroll_recursion=-1')
def dfs(SS, x):
    if len(SS)==1:
        ans[SS[0][1]] = x-1
        return
    NS = [[] for _ in range(26)]
    for s in SS:
        if len(s[0])==x: ans[s[1]]=x
        else:
            NS[ord(s[0][x])-ord("a")].append(s)
    for i in range(26):
        if NS[i]:dfs(NS[i], x+1)
dfs(S, 0)
print(*ans, sep="\n")