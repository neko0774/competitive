N, L, R = map(int, input().split())
L -= 1
S = [i+1 for i in range(N)]
S[L:R] = S[L:R][::-1]
print(*S)