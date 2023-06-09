import itertools as it
def main():
    N = int(input())
    K = int(input())
    A = [input() for _ in range(N)]
    ans = set()
    for iter in it.permutations(range(N), K):
        memo = ""
        for n in iter:
            memo += A[n]
        ans.add(memo)
    print(len(ans))

main()