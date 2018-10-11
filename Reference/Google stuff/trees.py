
# Source: http://openbookproject.net/thinkcs/python/english3e/trees.html

# class for trees
class Tree:
	def __init__(self, cargo, left=None, right=None):
		self.cargo = cargo
		self.left = left
		self.right = right
	
	def __str__(self):
		return str(self.cargo)

# calculates sum of cargos of this node and all its children
def total(tree):
	if tree == None:
		return 0
	return total(tree.left) + total(tree.right) + tree.cargo

def print_tree_preorder(tree):
	if tree is None:
		return
	print(str(tree.cargo) + " ")
	print_tree_preorder(tree.left)
	print_tree_preorder(tree.right)

def print_tree_inorder(tree):
	if tree is None: return
	print_tree_inorder(tree.left)
	print(str(tree.cargo) + " ")
	print_tree_inorder(tree.right)

def print_tree_postorder(tree):
	if tree is None: return
	print_tree_postorder(tree.left)
	print_tree_postorder(tree.right)
	print(str(tree.cargo) + " ")

def print_tree_indented(tree, level=0):
	if tree is None: return
	print_tree_indented(tree.right, level+1)
	print("  " * level + str(tree.cargo))
	print_tree_indented(tree.left, level+1)

# Returns true and pops if expected token is first on list, false otherwise
def get_token(token_list, expected):
	if token_list[0] == expected:
		del token_list[0]
		return True
	return False

# Returns tree with cargo of number and pops element if first on list is a number
def get_number(token_list):
	if get_token(token_list, "("):
		x = get_sum(token_list)
		if not get_token(token_list, ")"):
			raise ValueError("Missing close parenthesis")
		return x
	else:
		x = token_list[0]
		if type(x) != type(0): return None
		del token_list[0]
		return Tree(x, None, None)

# Builds expression tree for products
def get_product(token_list):
	a = get_number(token_list)
	if get_token(token_list, "*"):
		b = get_product(token_list)
		return Tree("*", a, b)
	return a

def get_sum(token_list):
	a = get_product(token_list)
	if (get_token(token_list, "+")):
		b = get_sum(token_list)
		return Tree("+", a, b)
	return a

# create expression tree for 1 + 2 * 3
tree = Tree("+", Tree(1), Tree("*", Tree(2), Tree(3)))

token_list = [9, "*", "(", 11, "+", 5, "*", 7, ")", "end"]
tree = get_sum(token_list)
print_tree_preorder(tree)
print "----------"
print_tree_inorder(tree)
print "----------"
print_tree_postorder(tree)
print()