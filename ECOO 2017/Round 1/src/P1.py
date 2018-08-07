# ECOO Round 1
# Victoria Park CI Team 1
# P1

with open("../DATA10.txt") as input:
    # string = map(str, input.read().split())
    # inputInt = map(int, input.readline().split())
    marks = [[] for i in xrange(1)]
    for i in xrange(1):
        weight = map(int, input.readline().split())
        numStudents = int(input.readline())
        for j in xrange(numStudents):
            marks[i].append(input.readline().strip())
    input.close()

print marks
