for i in range(10):
    w = int(input())
    lexi = list(map(str, input().split(" ")))
    s = ""
    while len(lexi) > 0:
        if len(lexi[0]) <= w:
            if len(s) + len(lexi[0]) + 1 <= w:
                if len(s) > 0:
                    s += " " + lexi[0]
                else:
                    s = lexi[0]
                lexi.pop(0)
            else: 
                print (s)
                s = lexi[0]
                lexi.pop(0)
        else: 
            if len(s) > 0:
                print (s)
            for j in range(0, len(lexi[0]), w):
                if len(lexi[0]) - j - 1 > w:
                    print (lexi[0][j:j+w])
                else:
                    s = lexi[0][j:]
                    # POP a cap up your ass
            lexi.pop(0)
    if len(s) > 0:
        print(s)
    print("=====")