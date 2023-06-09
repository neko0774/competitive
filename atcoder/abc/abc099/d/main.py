from collections import defaultdict
def main():
    N, C = map(int, input().split())

    D = [[int(i) for i in input().split()] for _ in range(C)]
    c = [[int(i)-1 for i in input().split()] for _ in range(N)]

    ans = 10**12
    colour = [defaultdict(int) for _ in range(3)]
    for x in range(N):
        for y in range(N):
            colour[(x+y)%3][c[y][x]]+=1

    for c1 in range(C):
        for c2 in range(C):
            for c3 in range(C):
                if c1==c2 or c2==c3 or c3==c1: continue
                Cs = [c1, c2, c3]
                memo = 0
                for fc in range(C):
                    for i in range(3):
                        memo += colour[i][fc]*D[fc][Cs[i]]
                ans = min(ans, memo)
    print(ans)
main()