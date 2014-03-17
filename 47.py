import os
from bisect import bisect_right

N = 1000000
cmd = './gen_prime {0}'.format(N)
os.system(cmd)

file_name = "primes_{0}.out".format(N)
f = open(file_name, "r")

a = map(int, f.readline().split())
s = set(a)

st = 4
step = 4
stack = []
while True:
    b = st
    M = {}
    index = bisect_right(a, b) - 1
    while b != 1:
        mod = a[index]
        while b % mod == 0:
            b /= mod
            if mod not in M:
                M[mod] = 1
            else:
                M[mod] += 1
        index -= 1
    print st, M
    if len(M) == step:
        if len(stack) == 0 or stack[-1] != st - 1:
            stack = [st]
        else:
            stack.append(st)
        if len(stack) == step:
            print stack[0]
            break

    st += 1
