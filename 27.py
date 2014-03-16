import os

N = 1000000
cmd = './gen_prime {0}'.format(N)
os.system(cmd)

file_name = "primes_{0}.out".format(N)
f = open(file_name, "r")

a = map(int, f.readline().split())
s = set(a)

ans = ()
mark = 0
for a in range(-999, 1000):
    for b in range(-999, 1000):
        temp = 0
        n = 0
        while (n ** 2 + a * n + b) in s:
            n += 1
        if mark < n:
            mark = n
            ans = (a, b)
            print mark, ans

print ans[0] * ans[1]

