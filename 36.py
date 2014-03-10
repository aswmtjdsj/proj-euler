def pan(x):
    """
    bla
    """
    i_x = [i for i in x]
    r_x = [i for i in i_x]
    r_x.reverse()
    return i_x == r_x

if __name__ == '__main__':
    ans = 0
    for i in range(1, 1000000):
        d = str(i)
        b = bin(i)[2:]
        if pan(d) and pan(b):
            print i
            ans += i
    print ans
