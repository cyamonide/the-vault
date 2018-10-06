import heapq

class Person:
	def __init__(self, name, age):
		self.name = name
		self.age = age

	def __lt__(self, comp):
		return self.age < comp.age

	def __repr__(self):
		return self.__str__()

	def __str__(self):
		return self.name

H = [Person("Charlie", 8), Person("Diana", 11), Person("Steve", 2), Person("Joe", 88)]

# Use heapify to rearrange the elements
heapq._heapify_max(H)
print(H)
heapq.heappush(H, Person("George", 0))
print(H)
heapq._heapify_max(H)
print(H)
