N = int(input())
bot = []
for _ in range(N):
    X, L = map(int, input().split())
    bot.append([X-L, X+L])
bot.sort()

R = -10**12
ans = 0
for l,r in bot:
    if R<=l:
        ans += 1
        R = r        
    else:
        R = min(R, r)
print(ans) 