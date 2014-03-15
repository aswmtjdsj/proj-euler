from itertools import permutations

w = {}

for i in range(10000):
    s = i ** 3
    has = list(str(s))
    has.sort()
    has = ''.join(has)
    if has not in w:
        w[has] = [s]
    else:
        w[has].append(s)

    if len(w[has]) > 4:
        w[has].sort()
        print w[has]
