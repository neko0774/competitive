H, W = map(int, input().split())
print(1 if H==1 or W==1 else (H*W+1)//2)