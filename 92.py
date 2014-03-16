one = set()
other = set()

for i in range(1, 10000000):
    b = i
    while b != 1 and b != 89:
        if b in one:
            one.add(i)
            break
        if b in other:
            other.add(i)
            break
        b = sum(map(lambda x:x * x, map(int, list(str(b)))))

    if b == 1:
        one.add(i)
    if b == 89:
        other.add(i)

print len(one)
print len(other)
