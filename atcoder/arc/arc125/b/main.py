mod = 998244353
def main():
    N = int(input())
    p = 1
    ans = 0
    while p*p<=N:
        ans += (N//p-p)//2+1
        ans %= mod
        p += 1
    print(ans)
main()