from collections import deque
def main():
    N, A, B = map(int, input().split())
    S = deque([i for i in input()])

    ans = 10**18
    def count(S):
        ret = 0
        for i in range(N//2):
            if S[i]!=S[-i-1]:
                ret += 1
        return ret

    for i in range(N):
        ans = min(ans, A*i+B*count(S))
        s = S.popleft()
        S.append(s)

    print(ans)
main()