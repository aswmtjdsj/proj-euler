import math
obj = 600851475143

print math.sqrt(obj)
for i in range( int(math.sqrt(obj))+2):
	if i <= 1: continue
	while (obj%i == 0):
		obj /= i
		print i, obj
