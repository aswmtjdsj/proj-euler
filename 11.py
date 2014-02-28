import sys, os

a = []
for line in sys.stdin:
    a.append(map(int, line.split(' ')))

print a

ans = 0
for i in range(len(a[0])):
    for j in range(len(a)):
        # horizontal
        if i + 4 < len(a[0]):
            temp = 1
            for k in range(i, i+4):
                temp *= a[j][k]
            if ans < temp:
                ans = temp
        # vertical
        if j + 4 < len(a):
            temp = 1
            for k in range(j, j+4):
                temp *= a[k][i]
            if ans < temp:
                ans = temp
        # diagonal, right 
        if i + 4 < len(a[0]) and j + 4 < len(a):
            temp = 1
            for k in range(j, j+4):
                q = k - j + i
                temp *= a[k][q]
            if ans < temp:
                ans = temp
        # diagonal, left
        if i + 4 < len(a[0]) and j >= 3:
            temp = 1
            for k in range(j-3, j+1):
                q = j - k + i
                temp *= a[k][q]
            if ans < temp:
                ans = temp

print ans
