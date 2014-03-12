def dfs(bla, size):
    """
    """
    if len(bla) == size:
        a = int(''.join(map(str, bla)))
        for i in range(2, 7):
            if set(bla) != set(map(int, list(str(a * i)))):
                return None
        return bla
    else:
        for i in range(10):
            if i not in bla:
                bla.append(i)
                res = dfs(bla, size)
                if res != None:
                    return res
                else:
                    bla.pop()

if __name__ == '__main__':
    for i in range(4, 11):
        ans = dfs([1], i)
        if ans:
            print ans
            break
