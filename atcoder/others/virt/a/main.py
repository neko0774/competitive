C = [input() for _ in range(4)]
for i in range(4)[::-1]:
  print(*C[i][::-1], sep = '')