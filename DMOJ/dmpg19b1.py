n = int(input())
a = list(map(int, input().split()))

b = 0
for i in a:
    b += i
    
if b > 200:
    print("Over maximum capacity!")
else:
    print(200 - b)
