# https://www.tutorialspoint.com/data_structures_algorithms/hash_data_structure.htm

SIZE = 40
hashArray = []

class DataItem:

	def __init__(self, data, key):
		self.data = data
		self.key = key

	def __str__(self):
		return str(self.data)

def hash_code(key):
	return key % SIZE

def search(key):
	hashIndex = hash_code(key)

	while hashArray[hashIndex] != None:
		if hashArray[hashIndex].key == key:
			return hashArray[hashIndex]

		hashIndex += 1

		hashIndex %= SIZE
	
	return None

def insert(key, data):
	item = DataItem(data, key)

	hashIndex = hash_code(key)

	# linear probe until found
	while hashArray[hashIndex] is not None and hashArray[hashIndex].key is not -1:
		hashIndex += 1
		hashIndex %= SIZE

	hashArray[hashIndex] = item

def delete(item):
	key = item.key

	hashIndex = hash_code(key)
	# something
	# this tutorial isn't great at all... not because it's in C++, but because
	#  it could use more explanation and comments in their example code

	return hashIndex

# python hashtables are simply dictionaries
dict = {'Name': 'Zara', 'Age' : 7, 'Class': 'First'}
del dict['Name'] # remove entry with key 'Name'
dict.clear()	# remove all entries in dict
del dict	# delete entire dictionary