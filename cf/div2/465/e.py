S = input()
P, M = map(int, input().split())

begin = 0
def expr():
    global begin
    ret = [-1]*(P+M)
    while begin<len(S):
        if S[begin].isdigit():
            pass
        elif S[begin] in "?":
            op = S[begin]
            begin += 1
        elif S[begin]=="(":
