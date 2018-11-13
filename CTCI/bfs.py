
import Queue

""" nah too complicated

class Node:
	def __init__(self, cargo=None, adj=[]):
		self.cargo = cargo
		self.adj = adj

	def __str__(self):
		return str(self.cargo) + ' ' + str(self.adj)

	def __repr__(self):
		return str(self.cargo) + ' ' + str(self.adj)

# source: https://i.stack.imgur.com/2wxai.png

root = Node(5, [Node(11)])

print root

"""

# represent this graph through a dict: https://i.stack.imgur.com/2wxai.png

adj = {}

nodes = [2, 3, 5, 7, 8, 9, 10, 11]

# 2
# 3
map(lambda x : adj.setdefault(3, []).append(x), [10, 8])
# 5
adj[5] = [11]
# 7
adj[7]= [8, 11]
# 8
adj[8] = [9]
# 9
# 10
# 11
adj[11] = [2, 9, 10]

visited = {}

def bfs(root):
	q = Queue.Queue()
	visited[root] = True

	q.put(root)

	while not q.empty():
		this_node = q.get()
		print this_node
		visited[this_node] = True

		for adj_node in adj.setdefault(this_node, []):
			if not visited.setdefault(adj_node, False):
				q.put(adj_node)


bfs(7)