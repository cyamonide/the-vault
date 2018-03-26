for query in range(10):

    w = int(input())    
    lexi = list(map(str, input().split(" ")))

    realLine = ""

    for a in lexi:

        # if not longer than
        if (len(realLine+" "+a) <= w):
            if (len(realLine) != 0):
                realLine += " "+a
            else:
                realLine += a
            continue

        # if longer than w
        if len(a) >= w:
            c = len(a)
            for b in range(0, c, w):
                print(a[:w])
                a = a[w:]
            realLine = a
            continue

        print(realLine)
        realLine = a

    if (len(realLine) != 0):
        print(realLine)

    print("=====")
        
        
            
