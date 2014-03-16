import os

N = 1000000
cmd = './gen_prime {0}'.format(N)
os.system(cmd)

file_name = "primes_{0}.out".format(N)
f = open(file_name, "r")

a = map(int, f.readline().split())
s = set(a)

ans = []
for i in a:
    b = i
    cur = set()
    mark = True
    while b not in cur: 
        cur.add(b)
        b = list(str(b))
        b = int(''.join(b[1:] + [b[0]]))
        if len(str(b)) < len(str(i)) or b not in s:
            mark = False
            break
    if mark: # in case of "11", we cannot use len(cur) == len(str(i))
        ans.append(i)

print ans, len(ans)

