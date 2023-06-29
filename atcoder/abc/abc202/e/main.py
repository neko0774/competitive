N = int(input())
P = [int(i) for i in input().split()]

table = [[-1]*N.bit_length() for i in range(N)]



Q = int(input())
for _ in range(Q):
  U, D = map(int, input().split())
