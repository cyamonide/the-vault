a = list(map(int, input().split()))
print('trans' if (min(a[0], a[2]) > max(a[1], a[3])) or (min(a[1], a[3]) > max(a[0], a[2])) else 'cis')