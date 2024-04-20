S = [i for i in input()]
from collections import Counter, defaultdict
C = Counter(S)
count = defaultdict(int)
for n in C.values():
  count[n] += 1
for i in count.values():
  if i!=0 and i!=2:
    print("No")
    exit()
print("Yes")