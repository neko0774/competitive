import heapq


def main():
    N, K = map(int, input().split())
    V = [int(i) for i in input().split()]
    
    def solve(R, L):
        point_left = K-R-L
        ret = 0
        neg = []
        for l in range(L):
            ret += V[l]
            if V[l]<0: heapq.heappush(neg, V[l])
        for r in range(R):
            ret += V[-r-1]
            if V[-r-1]<0: heapq.heappush(neg, V[-r-1])
        
        while neg and point_left>0:
            ret -= heapq.heappop(neg)
            point_left -= 1
        return ret
    ans = 0
    for r in range(N+1):
        for l in range(N+1):
            if r+l>N or r+l>K: break
            ans = max(ans, solve(r, l))
    print(ans)

main()