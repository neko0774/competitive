def main():
    N = int(input())
    box = []
    def find_least(x):
        ret = -1
        dif = 10**8
        for n,b in enumerate(box):
            if b>=x and b-x<dif:
                dif = b-x
                ret = n
        return ret


    for i in range(N):
        w = int(input())
        i = find_least(w)
        if i==-1:
            box.append(w)
        else:
            box[i] = w
    print(len(box))
main()