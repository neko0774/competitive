N, K = map(int, input().split())
S = [i for i in input()]

def next_letter(S):
    for s in range(len(S)):
        #change according to if its capital letter or not
        S[s] = ord(s)-ord("A")
    nex = []
    last_time = [-1]*27
    for n, s in enumerate(S)[::-1]:
        last_time[s] = n
        nex.append(last_time[:])
    return nex[::-1]

