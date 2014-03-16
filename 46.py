import os

N = 1000000
cmd = './gen_prime {0}'.format(N)
os.system(cmd)

file_name = "primes_{0}.out".format(N)
f = open(file_name, "r")

a = map(int, f.readline().split())
s = set(a)

sq = set(map(lambda x:x **2, range(1, 1000)))

c = 9 # all are composite numbers
while True:
    mark = False
    if c in a:
        mark = True
    if mark == False:
        for i in a:
            if i < c and ((c - i) / 2.) in sq:
                print "{0} = {1} + 2x{2}".format(c, i, (c-i)/2)
                mark = True
    if mark == False:
        print c
        break
    c += 2
