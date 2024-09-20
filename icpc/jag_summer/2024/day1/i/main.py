N = int(input())
clms = []
for i in range(N):
  bib, a, b, c = map(int, input().split())
  clms.append((a * b * c, a + b + c, bib))
clms.sort()
print(clms[0][-1], clms[1][-1], clms[2][-1])