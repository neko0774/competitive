def main():
    H, W = map(int, input().split())
    S = [[i for i in input().split()] for _ in range(H)]
    for y in range(H):
        for x in range(W):
            if S[y][x]=="snuke":
                print(str(chr(ord("A")+x))+str(y+1))
                return

main()