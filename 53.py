#
# C(n, r) = n!/(r!*(n-r)!)
# = n * (n-1) * ... * (n - r + 1) / r!

# C(n-1, r-1) = (n-1)!/((r-1)!*(n-r)!)
# = (n-1) * (n-2) * ... * (n-r+1) / (r-1)!

# C(n, r-1) = n!/((r-1)!*(n-r+1)!)
# = n * (n-1) * ... * (n-r+2) / (r-1)!

# C(n, r-1) - C(n-1, r-1) = (n - (n-r+1)) * (n-1) * .. * (n-r+2) / (r-1)!
# = (n-1) * ... * (n-r+2) / (r-2)!
# = C(n-1, r-2)

# thus
# C(n+1, r) = C(n, r) + C(n, r-1)
# C(5, 2) + C(5, 3) = 20 = C(6, 3)

C = {}
for i in range(1, 101):
    C[i] = {}
    C[i][0] = 1
    C[i][1] = i
    if i > 1:
        for j in range(2, (i/2)+1):
            C[i][j] = C[i-1][j] + C[i-1][j-1]
        for j in range((i/2)+1, i+1):
            C[i][j] = C[i][i-j]

ans = 0
for i in range(1, 101):
    for j in range(i+1):
        print 'C[{0}][{1}]: {2}'.format(i, j, C[i][j])
        if C[i][j] > 1000000:
            ans += 1
print 'ans: {0}'.format(ans)
