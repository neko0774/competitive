S = [i for i in input()] 
ops = set(["+", "*", "-", "/"])
x = 0
import sys
sys.setrecursionlimit(10**7)

def number():
    global x
    ret = ""
    while x<len(S) and S[x].isdigit():
        ret += S[x]
        x += 1
    return ret



def expr():
    global x
    ret = ""
    if S[x].isdigit():
        ret += number()
        return ret
    
    if S[x] in ops:
        op = S[x]
        x += 2
        ret += "("
        while x<len(S):
            if S[x]==",":
                ret += op
                x += 1
            elif S[x]==")":
                ret += ")"
                x += 1
                return ret
            else:
                ret += expr()


print(expr())