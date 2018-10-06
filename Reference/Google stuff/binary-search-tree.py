class Node:
	def __init__(self, data, left=None, right=None):
		self.data = data
		self.left = left
		self.right = right

	def insert(self, data):
		# let this binary search tree not have duplicate values
		if self.data == data:
			return

		if data < self.data:
			if self.left == None:
				self.left = Node(data)
			else:
				self.left.insert(data)
		elif data > self.data:
			if self.right == None:
				self.right = Node(data)
			else:
				self.right.insert(data)
	
	def find_val(self, data):
		if data < self.data:
			if (self.left == None):
				return str(data) + " not found"
			else:
				return self.left.find_val(data)
		elif data > self.data:
			if (self.right == None):
				return str(data) + " not found"
			else:
				return self.right.find_val(data)
		
		return str(data) + " found"

	def PrintTree(self):
		if self.left:
				self.left.PrintTree()
		print( self.data),
		if self.right:
				self.right.PrintTree()

root = Node(12)
root.insert(6)
root.insert(14)
root.insert(3)
print(root.find_val(7))
print(root.find_val(14))