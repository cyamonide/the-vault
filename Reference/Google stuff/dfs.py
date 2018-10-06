class Node:
	def __init__(self, data, adj=[]):
		self.data = data
		self.adj = adj

	def __str__(self):
		return str(self.data)

""" object oriented implementation
class Graph:
	def __init__(self, nodes=[]):
		# nodes of this graph
		self.nodes = nodes

	def dfs(self, root, visited=set()):
		if root in visited: return

		# set root as visited
		visited.add(root)
		print(root)

		# perform dfs on adjacent nodes
		for next in root.adj:
			self.dfs(next)

n1 = Node(1)
n2 = Node(2)
n3 = Node(3)
n4 = Node(4)
n5 = Node(5)

n1.adj = [n2, n3]
n2.adj = [n1, n4]
n3.adj = [n1, n4]
n4.adj = [n5]
n5.adj = [n1]

G = Graph([n1, n2, n3, n4, n5])

G.dfs(G.nodes[0])
"""

def dfs(graph, start, visited = set()):
	visited.add(start)
	print(start)

	for next in graph[start] - visited:
		dfs(graph, next, visited)
	
	return visited

gdict = { 1 : set([2, 3]),
	2 : set([1, 4]),
	3 : set([1, 4]),
	4 : set([5]),
	5 : set([1]) }

dfs(gdict, 1)