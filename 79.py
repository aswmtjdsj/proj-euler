import sys

# build graph
graph = {}
for line in sys.stdin:
    a = map(int, list(line.strip()))
    for i in enumerate(a):
        for j in enumerate(a):
            if i[0] < j[0]:
                if i[1] not in graph:
                    graph[i[1]] = set([j[1]])
                else:
                    graph[i[1]].add(j[1])

# find source
seq = []
for i in graph.keys(): 
    mark = True
    for j in graph.values():
        if i in j:
            mark = False

    if mark:
        print i
        seq.append(i)

# continue
for i in seq:
    print i
    if i not in graph:
        break
    for j in graph[i]:
        mark = True
        for k in graph.items():
            if k[0] not in seq:
                if j in k[1]:
                    mark = False
        if mark and j not in seq:
            seq.append(j)
            break
    print seq

print seq
