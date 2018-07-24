from bs4 import BeautifulSoup
from PriceTrackerBase import simple_get

url = 'https://www.amazon.ca/JBL-Waterproof-Portable-Bluetooth-Speaker/dp/B01F24RHF4/ref=sr_1_4?ie=UTF8&qid=1532398542&sr=8-4&keywords=jbl+charge+3'

with open('out.html', 'w') as file:
	raw_html = simple_get(url)
	html = BeautifulSoup(raw_html, 'html.parser')
	file.write(str(html))