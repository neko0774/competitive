def main():
    N = int(input())
    X = [int(i) for i in input().split()]

    ans = 10**9
    for pos in range(101):
        dist = 0
        for x in X:
            dist += (pos-x)**2
        ans = min(ans, dist)
    print(ans)
main()
            