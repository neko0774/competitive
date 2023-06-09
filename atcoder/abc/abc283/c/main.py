from collections import deque
def main():
    S = deque([s for s in input()])
    ans = 0
    while S:
        if len(S)>=2 and S[0]==S[1]=="0":
            ans += 1
            S.popleft()
            S.popleft()
        else:
            ans += 1
            S.popleft()
    print(ans)
main()