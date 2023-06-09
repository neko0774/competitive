from bisect import bisect_left as bl

def main():
    S = [i for i in input()]
    box = set()
    letters = [[] for _ in range(26)]
    cnt = 0
    place = []
    for n,s in enumerate(S):
        if s=="(":
            place.append(n)
            cnt = 0
        elif s==")":
            cnt += 1
            pos = place.pop()
            for n,l in enumerate(letters):
                left = bl(l, pos)
                if left<len(l):
                    box.discard(chr(ord("a")+n))
        else:
            letters[ord(s)-ord("a")].append(n)
            if s in box:
                print("No")
                return
            else:
                box.add(s)
    print("Yes")

main()