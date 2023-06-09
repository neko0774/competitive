import heapq
def main():
    N, M = map(int, input().split())
    jobs = dict()
    choices = []
    for _ in range(N):
        A, B = map(int, input().split())
        if A not in jobs:
            jobs[A] = [B]
        else:
            heapq.heappush(jobs[A], B)
    ans = 0
    for i in range(1, M+1):
        if i in jobs:
            for v in jobs[i]:
                heapq.heappush(choices, -v)
        if choices: ans += -heapq.heappop(choices)
    print(ans) 
main()