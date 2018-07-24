import TrackerNewegg

print(TrackerNewegg.getPrice('https://www.newegg.ca/Product/Product.aspx?Item=9SIAD3M6NY0446'))
print(TrackerNewegg.getPrice('https://www.newegg.ca/Product/Product.aspx?item=N82E16820168038'))
print(TrackerNewegg.getPrice('https://www.newegg.ca/Product/Product.aspx?item=N82E16820168040'))

TrackerNewegg.getId('https://www.newegg.ca/Product/Product.aspx?item=N82E16820168040')

print(TrackerBestBuy.getPrice('https://www.bestbuy.ca/en-ca/product/jbl-jbl-charge-3-waterproof-wireless-bluetooth-speaker-black-jblcharge3blkam/10424278.aspx?'))