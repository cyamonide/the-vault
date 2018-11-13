import Queue

"""
Queue
"""

q = Queue.Queue()

map(lambda x : q.put(x), [3, 6, 2, 3, 7])

print "regular queue"

while not q.empty():
	print q.get()

"""
Stack
"""

# stack
stack = Queue.LifoQueue()

map(lambda x : stack.put(x), [3, 6, 2, 3, 7])

print "stack"

while not stack.empty():
	print stack.get()


"""
Priority Queue
"""

p = Queue.PriorityQueue()

p.qsize()
p.empty()
p.full()

# put 5 in queue
p.put(5)
map(lambda x : p.put(x), [4, 6, 2, 7])

while not p.empty():
	print p.get()

# pairs
map(lambda x : p.put(x), [(1, 'foobar'), (3, 5), (2, 6), (6, 4), (1, 'foobat'), (1, 'alex')])

print "now, an example with pairs"

while not p.empty():
	print p.get()

# max heap
map(lambda x : p.put([-x[0], x[1]]), [(1, 'foobar'), (3, 5), (2, 6), (6, 4), (1, 'foobat'), (1, 'alex')])

print "max heap"

while not p.empty():
	print p.get()