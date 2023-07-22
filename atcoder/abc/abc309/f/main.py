N = int(input())
box = []
def compress(lis):
  ls = {j:i for i,j  in enumerate(sorted(set(lis)))}
  return [ls[i] for i in lis]
  
H = [0]*N
W = [0]*N
D = [0]*N
for i in range(N):
  h, w, d = map(int, sorted(input().split()))
  H[i] = h
  W[i] = w
  D[i] = d
H = compress(H)
W = compress(W)
D = compress(D)
box = [[h, w, d] for h, w, d in zip(H, W, D)]
box.sort()
print(box)