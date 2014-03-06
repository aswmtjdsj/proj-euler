import sys, os

def func(a, b):
    integer = a / b
    modulo = a % b
    frac = []
    modulo_set = []
    frac_non = []
    frac_cyc = []

    while modulo != 0:

        modulo *= 10
        cur = modulo / b
        if modulo not in modulo_set:
            frac.append(cur)
            modulo_set.append(modulo)
            modulo %= b
        else:
            ind = modulo_set.index(modulo)
            frac_non = frac[:ind]
            frac_cyc = frac[ind:]
            break

    if len(frac_cyc) == 0:
        frac_non = frac
    print '{0}{1}{2}{3} {4}'.format(integer, '.' if len(frac_non) > 0 or len(frac_cyc) > 0 else '', ''.join(map(str, frac_non)) if len(frac_non) > 0 else '', '(' + ''.join(map(str, frac_cyc)) + ')' if len(frac_cyc) > 0 else '', len(frac_cyc))
    return len(frac_cyc)


if __name__ == "__main__":
    for line in sys.stdin:
        a, b = map(int, line.split(' '))
        func(a, b)

