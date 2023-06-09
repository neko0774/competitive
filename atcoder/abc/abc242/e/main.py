mod = 998244353

#if the first half is decided, the last half is determined 



def solve(S, N):
    ret = 0
    x = N//2
    front = S[:x]
    back = S[-x:]
    
    change = 0 if front[::-1] > back else 1
    for i in front:
        ret = (ret*26+ord(i)-ord("A"))%mod
    if N%2==1:
        return (ord(S[x])-ord("A")+ret*26+change)%mod
    else:
        return (ret+change)%mod




def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        S = input()
        print(solve(S, N))

main()