K = int(input())

def op(ary):
  v = min(ary)
  first = 1 
  for i in range(50):
    if v == ary[i] and first:
      ary[i] += 50
      first = 0
    else:
      ary[i] -= 1
  return ary


ary = [K // 50 + i for i in range(50)]
for _ in range(K % 50):
  ary = op(ary)

print(len(ary))
print(*ary)