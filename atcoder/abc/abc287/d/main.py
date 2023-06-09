def main():
    S = input()
    T = input()
    ans = []

    cnt = 0
    clear = [0]*len(T)
    for t in range(len(T)):
        if S[t]=="?" or T[t]=="?" or T[t]==S[t]:
            clear[t] = 1
        else:
            cnt += 1
    if cnt==0: ans.append("Yes")
    else: ans.append("No")

    for t in range(1, len(T)+1):
        t = -t
        if clear[t]==0:
            cnt -= 1

        if T[t]!=S[t] and T[t]!="?" and S[t]!="?":
            cnt += 1

        if cnt==0:
            ans.append("Yes")
        else:
            ans.append("No")
    print(*ans[::-1], sep="\n")


main()