def sort_divisions(number):#約数列挙
    i = 2
    front, back = [1],[number]
    while i*i <= number:
        if number%i==0:
            front.append(i)
            if i!=number//i: back.append(number//i)
        i+=1
    return front+back[::-1]

inf = 10**12
from collections import defaultdict
def main():
    N, K = map(int, input().split())
    S = input()

    if N==1:
        ans = 1

    ans = inf
    def solve(x):
        r = N//x
        change = [defaultdict(int) for _ in range(r)]
        cnt = 0
        for n,s in enumerate(S):
            change[n%r][s] += 1
        for c in change:
            cnt += x-max(c.values())
        return r if cnt<=K else inf
    Ns = sort_divisions(N)
    for n in Ns:
        ans = min(solve(n), ans)
    print(ans)
main()