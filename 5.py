def gcd( x, y):
	return x if y == 0 else gcd( y, x % y)
def mmd( x, y):
	return x* y / gcd( x, y)

ans = 1
for i in range( 1, 21):
	ans = mmd( ans, i)
	print ans
