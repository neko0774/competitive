while True:
  N, D = map(int, input().split())
  if N==D==0: exit()
  game = []
  for _ in range(N):
    a,b = map(int, input().split())
    game.append([a, b, a])
  game.sort(reverse=True)
  ans = 0
  last_use = -1
  if N==1:
    for _ in range(D):
      ans += game[0][0]
      game[0][0] -= game[0][1]

  else:
    for _ in range(D):
      if game[0][0]>game[1][0]:
        ans += game[0][0]
        game[0][0] -= game[0][1]
        use = 0
      else:
        ans += game[1][0]
        game[1][0] -= game[1][1]
        use = 1
      if last_use != -1:
        game[last_use][0] = min(game[last_use][0]+game[last_use][1], game[last_use][-1])
      last_use = use
  print(ans)