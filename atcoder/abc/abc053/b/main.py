S = input()
st = 10**7
ed = 0
for n in range(len(S)):
    if S[n]=="A": st = min(st, n)
    if S[n]=="Z": ed = max(ed, n)

print(ed-st+1)