from bisect import bisect_left as bl
inf = 10**12
def LIS2(array):
    dp = [array[0][1]]
    pos = [array[0][0]]
    for a, b in array:
        index = bl(dp, b)
        if pos[-1]==a: continue
        if b>dp[-1]:
            dp.append(b)
            pos.append(a)
        elif dp[index]==b:
            continue
        else:
            dp[index] = b
            pos[index] = a
    #print(dp, pos)
    return len(dp)


def main():
    N, M = map(int, input().split())
    A = set()
    L = []
    for _ in range(M):
        a,b = map(int, input().split())
        a -= 1
        b -= 1
        L.append([a, b])
    L.sort()
    #print(L)
    print(LIS2(L))



main()