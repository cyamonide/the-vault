#!/bin/python3

class Node(object):
    def __init__(self, cargo):
        self.cargo = cargo
        self.left = None
        self.right = None

    def insert(self, cargo):
        if cargo <= self.cargo:
            if self.left:
                self.left.insert(cargo)
            else:
                self.left = Node(cargo)
        else:
            if self.right:
                self.right.insert(cargo)
            else:
                self.right = Node(cargo)

    def prefix(self):
        print(self.cargo)
        self.left and self.left.prefix()
        self.right and self.right.prefix()

    def infix(self):
        self.left and self.left.infix()
        print(self.cargo)
        self.right and self.right.infix()

tree = Node(5)

tree.insert(3)
tree.insert(2)
tree.insert(6)
tree.insert(4)

tree.infix()
print("-----------------")
tree.prefix()