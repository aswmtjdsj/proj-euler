def fibo():
	a = 1
	b = 2
	ans = 2
	while( True):
		a = a + b
		print a,
		if a >= 4000000:
			break
		ans += a if a % 2 == 0 else 0
		b = a + b
		print b,
		if b >= 4000000:
			break
		ans += b if b % 2 == 0 else 0
	return ans

print 'ans: {0}'.format(fibo())
