N = int(input())
H = [int(i) for i in input().split()]

T = 0
for h in H:
  T += h // 5 * 3
  h %= 5
  while h > 0:
    T += 1
    if T % 3 == 0:
      h -= 3
    else:
      h -= 1
print(T)