class Node:
	def __init__(self, data):
		self.direct_children = []
		self.children_dist = {}
		self.data = -1

class Solution(object):

    def sumOfDistancesInTree(self, N, edges):
        """
        :type N: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """

        # optimized hashing shortest path solution

        # BFS but once reached n<root, end search for 
        #  that node and set all of its children to visited

		adj = [[] for _ in xrange(N)]

		# array containing shortest path hashes
		sp = []
		# {'sum', 'adj (to be or'd)', 'count of children'}

        for p in edges:
        	adj[p[0]].append(p[1])
        	adj[p[1]].append(p[0])

        dists = []

        for root in xrange(N):

        	visited = [0]*N
        	visited[root] = 1
        	dist_sum = 0
        	dist_current = 0

        	q = []
        	for a in adj[root]:
        		q.append(a)

        	while q:
        		# increment distance
        		dist_current += 1

        		size = len(q)
        		for _ in xrange(size):
        			if q[0] < root:
        				# map already exists

        				adj &= sp[q[0]]['adj']


        			if visited[q[0]]:
        				q.pop(0)
        				continue
        			else:
        				dist_sum += dist_current
        				visited[q[0]] = 1
        				for a in adj[q[0]]:
        					q.append(a)
        			q.pop(0)

        	dists.append(dist_sum)

        return dists


        # naive BFS solution
        """
        adj = [[] for _ in xrange(N)]

        for p in edges:
        	adj[p[0]].append(p[1])
        	adj[p[1]].append(p[0])

        dists = []

        for root in xrange(N):

        	visited = [0]*N
        	visited[root] = 1
        	dist_sum = 0
        	dist_current = 0

        	q = []
        	for a in adj[root]:
        		q.append(a)

        	while q:
        		# increment distance
        		dist_current += 1

        		size = len(q)
        		for _ in xrange(size):
        			if visited[q[0]]:
        				q.pop(0)
        				continue
        			else:
        				dist_sum += dist_current
        				visited[q[0]] = 1
        				for a in adj[q[0]]:
        					q.append(a)
        			q.pop(0)

        	dists.append(dist_sum)

        return dists
        """

		# or, treat tree as a tree
		# dist from child to parent is 1
		# keep on going up until a common parent is found
		# add dist from that parent to child 1 to child 2

		# DP problem

		# each node should have a dict with children nodes as
		#  keys and distances as values

		# to find sum of distances, from A,
		#  - calculate distance from A to a parent
		#  - multiply that distance by number of children (-1)
		#  - add all children values (except itself)
		#  - continue to next parent

		# create tree
		# each node should have a dict child_node:dist_to_child
		# 

		# https://leetcode.com/problems/sum-of-distances-in-tree/description/

sol = Solution()
print sol.sumOfDistancesInTree(6, [[0,1],[0,2],[2,3],[2,4],[2,5]])