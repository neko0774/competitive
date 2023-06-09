Y, X, K = map(int, input().split())
item = dict()
for _ in range(K):
    y, x, k = map(int, input().split())
    item[(x, y)] = k


dp = []