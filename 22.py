import sys, os

f = open("names.txt", "r")
for line in f:
    biu = line.replace('"', '').replace('\n', '').replace(',', ' ').split(' ')
    biu.sort()
    ans = 0
    print biu
    for i in enumerate(biu):
        temp = 0
        for j in i[1]:
            temp += ord(j) - ord('A') + 1
        ans += temp * (i[0] + 1)
    print ans
