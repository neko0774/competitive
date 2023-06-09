x = int(input())
ans = x//11*2
x %= 11
if x==0: ans += 0
elif x<=6: ans += 1
else: ans += 2
print(ans)