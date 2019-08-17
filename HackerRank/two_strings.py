# Enter your code here. Read input from STDIN. Print output to STDOUT

p = int(input())

def sol():
    s1 = set(input())
    s2 = input()
    for i in s2:
        if i in s1:
            print("YES")
            return
    print("NO")

for _ in range(p):
    sol()