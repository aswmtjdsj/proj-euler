ans = 1
for i in range(1, 1000000):
    cnt = 1
    n = i
    while n != 1:
        if n % 2 == 1:
            n = 3 * n + 1
        else:
            n = n / 2
        cnt += 1
    if ans < cnt:
        ans = cnt
        print i, cnt
