# represent this graph through a dict: https://i.stack.imgur.com/2wxai.png

adj = {}

nodes = [2, 3, 5, 7, 8, 9, 10, 11]

map(lambda x : adj.setdefault(3, []).append(x), [10, 8])
adj[5] = [11]
adj[7]= [8, 11]
adj[8] = [9]
adj[11] = [2, 9, 10]

visited = {}

def dfs(root):
	if visited.setdefault(root, False):
		return

	print root
	visited[root] = True
	for adj_node in adj.setdefault(root, []):
		if not visited.setdefault(adj_node, False):
			dfs(adj_node)

dfs(3)