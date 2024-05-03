N, Q = map(int, input().split())
T = [int(i) for i in input().split()]

ans = N
not_teeth = set()
for t in T:
  if t in not_teeth:
    ans += 1
    not_teeth.discard(t) 
  else:
    ans -= 1
    not_teeth.add(t)
print(ans)