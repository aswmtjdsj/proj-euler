import sys, os, random

# 9! * 7 < 9999999

ans = 0
for length in range(2, 7):
    for i in range(10 ** (length-1), 10 ** length):
        a = map(int, [j for j in str(i)])
        left = sum([reduce(lambda x, y: x * y, range(1, j+1)) if j > 0 else 1 for j in a] )
        right = i
        if left == right:
            print left, right
            ans += right

print ans
