import collections

def bfs(graph, start):
	visited, queue = set([start]), collections.deque([start])

	while queue:
		vertex = queue.popleft()
		print(vertex)
		
		for node in graph[vertex]:
			if node not in visited:
				visited.add(node)
				queue.append(node)

gdict = { 1 : set([2, 3]),
	2 : set([1, 4]),
	3 : set([1, 4]),
	4 : set([5]),
	5 : set([1]) }

bfs(gdict, 1)