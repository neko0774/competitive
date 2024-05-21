N = int(input())
card = []
for i in range(N):
  a, c = map(int, input().split())
  card.append([a, c, i+1])

card.sort(reverse=True)
ans = [card[0][-1]]
mi = card[0][1]
for _, c, i in card[1:]:
  if c<mi:
    mi = c
    ans.append(i)
print(len(ans))
ans.sort()
print(*ans)