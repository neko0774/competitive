S = input()
ans = 0
for n,s in enumerate(S[::-1]):
    ans += (ord(s)-ord("A")+1)*26**n
print(ans)