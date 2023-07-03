S = [int(i) for i in input().split()]
ls = S[0]
for s in S:
  if not s%25==0 or not ls<=s or not 100<=s<=675:
    print("No")
    exit()
  ls = s
print("Yes")