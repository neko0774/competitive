N, M = map(int, input().split())
is_born = [0 for _ in range(N)]
for i in range(M):
  a, b = input().split()
  a = int(a) - 1
  if b == 'M' and not is_born[a]:
    print("Yes")
    is_born[a] = 1
  else:
    print("No")