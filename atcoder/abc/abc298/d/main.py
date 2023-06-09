Q = int(input())
from collections import deque
num = 1
S = deque([1])
mod = 998244353

for _ in range(Q):
    t = input()
    if t[0]=="1":
        _, x = map(int, t.split())
        S.append(x)
        num *= 10
        num += x
        num %= mod
    elif t[0]=="2":
        n = S.popleft()
        num -= n*pow(10, len(S), mod)%mod
        num %= mod
    else:
        print(num%mod)