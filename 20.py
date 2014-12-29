print sum(map(int, [i for i in str(reduce(lambda x,y: x * y, range(1, 1001)))]))
