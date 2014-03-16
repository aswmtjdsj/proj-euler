ans = 0
for i in range(1, 100):
    for j in range(1, 100):
        ans = max(ans, sum(map(int, list(str(i ** j)))))
print ans
