ans = 0
for i in range(1, 1000000):
    a = set()
    b = i
    while b not in a:
        a.add(b)
        b = sum(map(lambda x: reduce( lambda y, z: y * z, [1,1] + range(1, x+1)) , map(int, list(str(b)))))

    if len(a) == 60:
        print i, len(a)
        ans += 1

print ans
