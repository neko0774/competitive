N = int(input())
event = []
for i in range(N):
  l, r = map(int, input().split())
  event.append([l, 0])
  event.append([r, 1])
event.sort()
ans = 0
memo = 0
for l, c in event:
  if c==0:
    ans += memo
    memo += 1
  else:
    memo -= 1

print(ans)