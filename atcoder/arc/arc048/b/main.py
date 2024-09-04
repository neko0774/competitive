N = int(input())
R = []
H = []
hand = dict()
for _ in range(N):
  r, h = map(int, input().split())
  h -= 1
  R.append(r)
  H.append(h)
  if not r in hand:
    hand[r] = [0, 0, 0]
  hand[r][h] += 1

print(hand)
ans = dict()
win = 0
for key, values in sorted(hand.items()):
  print(key, values)
  for i in range(3):
    win_cur = win + values[i % 3]
    lose_cur = lose + values[(i - 1) % 3]
  win += sum(values)