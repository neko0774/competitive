N, K = map(int, input().split())
drag = []
cnt = 0
day = 0
for _ in range(N):
  a, b= map(int, input().split())
  cnt += b
  day = max(day, a)
  drag.append([a, b])
drag.append([0, 0])
drag.sort()
drag.append([day+1, 0])
for a, b in drag:
  cnt -= b
  if cnt<=K:
    print(a+1)
    exit()