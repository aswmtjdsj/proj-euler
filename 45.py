import sys
T = {}
P = {}

n = int(raw_input())
for i in range(1, n):
    T[i * (i+1) / 2] = i
    P[i * (3*i-1) / 2] = i

for i in range(1, n):
    h = i * (2*i-1)
    if h in T and h in P:
        print h
