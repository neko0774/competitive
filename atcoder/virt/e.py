N, X = map(int, input().split())
size = [1]
meat = [1]
for n in range(N):
  size.append(size[-1] * 2 + 3)
  meat.append(meat[-1] * 2 + 1)

def count(l, x):
  if l == 0:
    if x > 0: return 1
    return 0
  x -= 1
  if x <= size[l - 1]:
    return count(l - 1, x)
  x -= 1 + size[l - 1]
  return count(l - 1, x) + meat[l - 1] + 1

print(count(N, X))