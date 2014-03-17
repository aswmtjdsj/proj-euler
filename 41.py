import os
from bisect import bisect_right

N = 1000000000
# cmd = './gen_prime {0}'.format(N)
# os.system(cmd)

file_name = "primes_{0}.out".format(N)
f = open(file_name, "r")

a = map(int, f.readline().split())

for i in a:
    b = str(i)
    c = list(b)
    d = set(c)
    if len(d) == len(b) and '0' not in c and len(filter(lambda x:int(x) <= len(b), c)) == len(b):
        print i
