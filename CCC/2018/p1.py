N = int(input())

road = []

for i in range(0, N):
  road.append(int(input()))

road = sorted(road)
  
midPoints = []
  
for i in range(1, N):
  midPoints.append(road[i-1] + abs((road[i] - road[i-1]))/2.0)
  
minDist = midPoints[1]-midPoints[0]
  
for i in range(1, N-1):
  if midPoints[i] - midPoints[i-1] < minDist:
    minDist = midPoints[i] - midPoints[i-1]
    
print(minDist)