from bs4 import BeautifulSoup
from PriceTrackerBase import simple_get

url = 'https://www.staples.ca/en/JBL-Charge-3-Portable-Bluetooth-Waterproof-Speaker-Black/product_2300581_1-CA_1_20001'

with open('out.html', 'w') as file:
	raw_html = simple_get(url)
	html = BeautifulSoup(raw_html, 'html.parser')
	file.write(str(html))