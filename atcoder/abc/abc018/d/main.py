N, M, P, Q, R = map(int, input().split())
import itertools as it
choco = []
for _ in range(R):
    x, y, z = map(int, input().split())
    choco.append([x, y, z])

for ii in it.products(range(N), P):