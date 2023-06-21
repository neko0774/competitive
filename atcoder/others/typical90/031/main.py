N = int(input())
W = [int(i) for i in input().split()]
B = [int(i) for i in input().split()]

g = dict()
g[(0, 1)] = 0
g[(0, 0)] = 0

def mex(S):
    for l in range(10**9):
        if l not in S: return l


def grundy(w, b):
    if (w, b) in g: return g[(w, b)]
    ns = set()
    if w-1>=0:ns.add(grundy(w-1, b+w))
    if b>=2:
        for bb in range(1, b//2+1):
            ns.add(grundy(w, b-bb))
    g[(w, b)] = mex(ns)
    return g[(w, b)]

n = 0
for w, b in zip(W, B):
    n ^= grundy(w, b)
print("Second" if n==0 else "First")