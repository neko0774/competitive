import heapq

while True:
  N, D = map(int, input().split())
  if N==D==0: exit()
  game = []
  for _ in range(N):
    a,b = map(int, input().split())
    heappush(game, (a, b))
  
  for _ in range(D):
    x, b = heappush(game)
    