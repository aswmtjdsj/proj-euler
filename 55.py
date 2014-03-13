limit = 50

ans = 0
for i in range(1, 10001):
    a = i
    for j in range(limit):
        b = list(str(a))
        b.reverse()
        b = int(''.join(b))
        t = a + b
        t_r = list(str(t))
        t_r.reverse()
        if ''.join(t_r) == str(t):
            ans += 1
            print t
            break
        a = t
print 10000 - ans
