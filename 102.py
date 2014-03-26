import sys, os

def left(p, q, s):
    # (s - p) ^ (q - p)
    ax = q[0] - p[0]
    ay = q[1] - p[1]
    bx = s[0] - p[0]
    by = s[1] - p[1]
    # print ax, ay, bx, by, ax * by - ay * bx
    return ax * by - ay * bx > 0

o = (0, 0)
cnt = 0
for line in sys.stdin:
    p = map(int, line.replace('\n', '').split(','))
    a = (p[0],p[1])
    b = (p[2],p[3])
    c = (p[4],p[5])
    if (left(a, b, c) and left(b, c, o) and left(c, a, o) and left(a, b, o)) or (left(b, a, c) and left(a, c, o) and left(c, b, o) and left(b, a, o)):
        cnt += 1
        print a, b, c, cnt
        # raw_input()

print cnt
