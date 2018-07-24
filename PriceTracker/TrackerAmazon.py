from PriceTrackerBase import simple_get
from bs4 import BeautifulSoup

def getPrice(url):
	"""
	Scrapes price of product from Amazon
	"""
	# Retrieve HTML
	html = BeautifulSoup(simple_get(url), 'html.parser')

	# Isolate price
	for meta in html.select('meta'):
		try:
			if meta['itemprop'] == 'price':
				return float(meta['content'])
		
		except KeyError:
			pass

	print("No price found at " + url)
	return None

def getId(url):
	print(url.split('=')[1])
	for a in url.split():
		print(a)