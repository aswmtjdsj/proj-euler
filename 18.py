import sys

a = []
for line in sys.stdin:
    a.append(map(int, line.split(' ')))

print a

