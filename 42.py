import sys

source = set(map(lambda x: x * (x + 1) / 2, range(1, 21)))
ans = 0
for line in sys.stdin:
    line = line.replace('"', '').split(',')
    for i in line:
        temp = sum(map(lambda x: ord(x) - ord('A') + 1, list(i)))
        if temp in source:
            ans += 1
    print ans

