N = int(input())
from collections import defaultdict
count = defaultdict(int)
for _ in range(N):
    s = "".join(sorted([i for i in input()]))
    count[s] += 1
ans = 0
for v in count.values():
    ans += v*(v-1)//2
print(ans)