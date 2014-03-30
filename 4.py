def is_pan( x):
	for i in range(len(x)):
		if x[i] != x[len(x)-i-1]:
			return False
	return True

ans = 0
for i in range(100, 1000):
	for j in range( i, 1000):
		a = i * j
		if is_pan( str(a)):
			print a
			ans = max(a,ans)
print "ans:{0}".format(ans)
