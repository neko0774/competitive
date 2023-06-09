import sys
sys.setrecursionlimit(10**6)
A = input()
B = input()

def decomp(tree):
    ret = []
    cnt = 0
    size = 0
    for t in tree:
        if t=="(": cnt += 1
        elif t==")": cnt -= 1
        elif t=="[":
            num = ""
        elif t=="]":
            ret.append([int(num), cnt])
            size = max(size, cnt)
        else:
            num += t
    place = [[] for _ in range(size)]
    for i in range(len(ret)):
        _, h = ret[i].split()
        place[h].append(i)
    return ret, place
deco_A, place_A = decomp(A)
deco_B, place_B = decomp(B)
from bisect import bisect_left as bl
def dfs(h, a_pos, b_pos):
    a_next = bl(place_A[h+1], a_pos)
    b_next = bl(place_B[h+1], b_pos)
    if a_next==0 or b_next==0 or a_next>len(place_A[h+1]) or b_next>len(place_B[h+1]):
        return "()["+deco_A[a_pos]+deco_B[b_pos]+"]()"
    return "("+dfs(h+1, a_next-1, b_next-1)+")"+"["+deco_A[a_pos]+deco_B[b_pos] +"]"+"("+dfs(h+1, a_next, b_next)+")"
print(dfs(0, place_A[0], place_B[0]))