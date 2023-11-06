X = int(input())
from collections import defaultdict
mod = 998244353

board = defaultdict(int)
board[X] = 1
is_changed = True
decided = [0]*4
while is_changed:
  next = defaultdict(int)
  is_changed = False
  for x, cnt in board.items():
    if x>3:
      next[x//2] += cnt
      next[-(-x//2)] += cnt
      is_changed = True
    else:
      decided[x] += cnt
  board = next

ans = 1
for x, times in enumerate(decided[2:]):
  ans *= pow(x+2, times, mod)
  ans %= mod
print(ans)