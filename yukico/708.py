import sys
sys.setrecursionlimit(10**7)
S = input()

begin = 0
def expr():
    global begin
    ret = 0
    op = ""
    while begin<len(S):
        if S[begin]=="+":
            op = "+"
            begin += 1
        elif S[begin]=="-":
            op = "-"
            begin += 1
        elif S[begin].isdigit():
            if op=="" or op=="+":
                ret += int(S[begin])
            else:
                ret -= int(S[begin])
            begin += 1
        elif S[begin]=="(":
            begin += 1
            if op=="+" or op=="":
                ret += expr()
            else:
                ret -= expr()
        elif S[begin]==")":
            begin += 1
            return ret
    return ret
    
print(expr())