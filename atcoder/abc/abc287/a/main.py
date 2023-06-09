N = int(input())
cnt = 0
for _ in range(N):
    if input()=="For": cnt += 1
print("Yes" if cnt*2>N else "No")