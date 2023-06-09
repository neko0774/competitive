N, D = map(int, input().split())
ppl = []
for n in range(N):
    X, Y = map(int, input().split())
    ppl.append([n, X, Y])

is_infected = [0]*N
is_infected[0] = 1
from collections import deque
q = deque([0])
while q:
    p = q.popleft()
    _, x, y = ppl[p]
    for n, nx, ny in ppl:
        if not is_infected[n] and (x-nx)**2+(y-ny)**2<=D**2:
            q.append(n) 
            is_infected[n] = 1
print(*["Yes" if i else "No" for i in is_infected], sep="\n")