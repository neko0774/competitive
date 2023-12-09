N = int(input())
S = [i for i in input()]
S.append('-')
from collections import defaultdict
count = defaultdict(int)
lst = '-'
length = 0
for s in S:
  if s==lst:
    length += 1
  else:
    count[lst] = max(count[lst], length)
    lst = s
    length = 1
print(count)
print(sum([n for i, n in count.items() if i!='-']))