x = 1
y = 1
f = x + y
cnt = 3
while len(str(f)) < 1000:
    x = y
    y = f
    f = x + y
    cnt += 1

print f, cnt
