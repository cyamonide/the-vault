import sys
input = sys.stdin.readline

N = int(input())

coords = []
# coordsy = []
for i in range(N):
    a = list(map(int, input().split()))
    coords.append([a[0], a[2], i+1])
    # coordsy.append([a[1], a[0], a[2], i+1])

coords = sorted(coords)
# coordsy = sorted(coordsy)

# for a in coords:
#     print(a)
# print("break")
# for b in coordsy:
#     print(b)
# print("endbreak")

found = False
for i in range(N-2):
    c = coords[i][1] + coords[i+1][1] + coords[i+2][1]
    if c == 3 or c == 6:
        continue
    else:
        print("{} {} {}".format(coords[i][2], coords[i+1][2], coords[i+2][2]))
        found = True
        break

# if not found:
#     for i in range(N-2):
#         c = coordsy[i][1] + coordsy[i+1][1] + coordsy[i+2][1]
#         if c == 3 or c == 6:
#             continue
#         else:
#             print("{} {} {}".format(coords[i][2], coords[i+1][2], coords[i+2][2]))
#             found = True
#             break

if not found:
    print(-1)