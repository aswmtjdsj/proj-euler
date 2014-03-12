num = 10000
ans = 0

for i in range(1, num):
    for j in range(2, 10):
        n = range(1, j)
        bla = ''.join(map(str, map(lambda x: x * i, n)))
        if len(bla) == 9 and len(set(list(bla))) == 9 and '0' not in bla:
            ans = max(int(bla), ans)
            print i, n, bla

print ans
