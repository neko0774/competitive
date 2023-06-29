from collections import deque
H, W = map(int, input().split())
A = [[1 if i=='+' else -1 for i in input()] for _ in range(H)]

score = [[0,0]*W for _ in range(H)]
turn = 0 if (H+W-2)%2==0 else 1
#0 Aoki
#1 Takahashi
#aoki minuis
#takahashi plus
score[-1][-1] = -A[-1][-1] if turn else A[-1][-1]
for x in range(1, W):
    score[-1][-x] = (-A[-1][-x] if x%2==0 else A[-1][-x])+score[-1][-x+1]
for y in range(1, H):
    score[y][-1] = (-A[y][-1] if y%2==0 else A[-y][-1])+score[-y+1][-1]