N = int(input())
S = [i for i in input()]

count = dict()
count_seen = dict()
for i in range(3):
    count[str(i)] = 0
    count_seen[str(i)] = 0
for s in S:
    count[s] += 1
for n,s in enumerate(S):
    if count[s]==N//3: continue
    elif count[s]>N//3: 
        for i in range(3):
            if count[str(i)]<N//3 and (str(i)<s or count_seen[s]==N//3):
                S[n] = str(i)
                count[s] -= 1
                count[str(i)] += 1
                break
    count_seen[S[n]] += 1
print("".join(S))