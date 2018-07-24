from requests import get
from requests.exceptions import RequestException
from contextlib import closing
from bs4 import BeautifulSoup

def simple_get(url):
	"""
	Attempts to get the content at `url` by making an HTTP GET request.
	If the content-type of response is some type of HTML/XML, return the 
	text content, otherwise return None.
	"""
	try:
		with closing(get(url, stream=True)) as resp:
			if is_good_response(resp):
				# print("Good response from " + url)
				return resp.content
			else:
				print("Bad response (non-HTML/XML) from " + url)
				return None

	except RequestException as e:
		log_error('Error during requests to {0} : {1}'.format(url, str(e)))
		return None

def is_good_response(resp):
	"""
	Returns True if the response seems to be HTML, False otherwise
	"""
	content_type = resp.headers['Content-Type'].lower()
	return (resp.status_code == 200
			and content_type is not None
			and content_type.find('html') > -1)

def log_error(e):
	"""
	This function prints errors
	"""
	print(e)