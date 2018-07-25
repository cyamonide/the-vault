import TrackerNewegg
import TrackerBestBuy
import TrackerStaples

print(TrackerNewegg.getPrice('https://www.newegg.ca/Product/Product.aspx?Item=9SIAD3M6NY0446'))
print(TrackerNewegg.getPrice('https://www.newegg.ca/Product/Product.aspx?item=N82E16820168038'))
print(TrackerNewegg.getPrice('https://www.newegg.ca/Product/Product.aspx?item=N82E16820168040'))

TrackerNewegg.getId('https://www.newegg.ca/Product/Product.aspx?item=N82E16820168040')

print(TrackerBestBuy.getPrice('https://www.bestbuy.ca/en-ca/product/jbl-jbl-charge-3-waterproof-wireless-bluetooth-speaker-black-jblcharge3blkam/10424278.aspx?'))
print(TrackerBestBuy.getPrice('https://www.bestbuy.ca/en-ca/product/kingston-a400-ssd-240gb-sata-3-2-5-internal-solid-state-drive-ssd-sa400s37-240g-increased-performance-500mb-s/12490330.aspx?'))

print(TrackerStaples.getPrice('https://www.staples.ca/en/JBL-Charge-3-Portable-Bluetooth-Waterproof-Speaker-Black/product_2300581_1-CA_1_20001'))