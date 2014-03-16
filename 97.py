limit = 25

def pw(a, n):
    if n == 0:
        return 1
    b = pw(a, n/2) ** 2
    if n % 2 != 0:
        b *= a
    b = int(''.join(list(str(b))[-limit:]))
    return b

if __name__ == '__main__':
    a, n = map(int, raw_input().split(' '))
    print pw(a, n)
    print str(28433 * pw(a, n) + 1)[-10:]
    # print str(a ** n)[-limit:]
