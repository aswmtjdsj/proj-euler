import sys

for line in sys.stdin:
    n = int(line)
    a = [x ** x for x in range(1, n+1)]
    s_a = str(sum(a))
    print s_a[len(s_a)-10:]
