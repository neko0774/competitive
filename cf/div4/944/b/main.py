from collections import Counter
T = int(input())
for _ in range(T):
  S = [i for i in input()]
  C = Counter(S)
  if len(C)==1:
    print("No")
  else:
    print("Yes")
    if sorted(S)==S:
      print(*sorted(S, reverse=True), sep="")
    else:
      print(*sorted(S), sep="")