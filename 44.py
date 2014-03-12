p = map(lambda x: x * (3 * x - 1) / 2, range(1, 10001))
sp = set(p)
ans = p[9998]

for i in range(len(p)):
    for j in range(i + 1, len(p)):
        if (p[j] - p[i]) in sp and (p[j] + p[i]) in sp:
            ans = min(p[j] - p[i], ans)
            print ans, p[j], p[i]

print ans
