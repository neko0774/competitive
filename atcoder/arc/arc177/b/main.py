N = int(input())
S = [int(i) for i in input()][::-1]

is_zero = True
ans = []
for n, s in enumerate(S):
  if (s==0 and is_zero) or (s==1 and not is_zero):
    continue
  else:
    for i in range(N-n):
      ans.append('A' if s==1 else 'B')
    is_zero = not is_zero
print(len(ans))
print("".join(ans))