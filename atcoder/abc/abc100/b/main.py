D, N = map(int, input().split())
d = 100**D
def count(x):
    ret = 0
    while x%100==0:
        ret += 1
        x //= 100
    return ret
cnt = 0
for n in range(d, 10**7, d):
    if count(n)==D:
        cnt += 1
        if cnt==N:
            ans = n
            break
print(ans)