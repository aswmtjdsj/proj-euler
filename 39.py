ans = 0
mark = 0
for i in range(3, 1001):
    t_ans = 0
    for a in range(1, i + 1):
        for b in range(1, i + 1 - a):
            c = i - a - b
            l = [a, b, c]
            l.sort()
            if 0 not in l and l[0] ** 2 + l[1] ** 2 == l[2] ** 2:
                t_ans += 1

    print t_ans, i

    if t_ans > ans:
        ans = t_ans
        mark = i

print ans / 3, mark

