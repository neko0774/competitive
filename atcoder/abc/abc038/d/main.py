from bisect import bisect_left as bl
inf = 10**12
def LIS(array):
    dp = [inf for _ in range(len(array))]
    for a in array:
        dp[bl(dp, a)] = a
    return bl(dp, inf)


def main():
    N = int(input())
    box = dict()
    for _ in range(N):
        w, h = map(int, input().split())
        if not w in box:
            box[w] = [h]
        else:
            box[w].append(h)
    
    B = []
    for k in sorted(box.keys()):
        box[k].sort(reverse=True)
        B += box[k]
    print(LIS(B))
main()