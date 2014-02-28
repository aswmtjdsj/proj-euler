from math import sqrt
def func():
    for c in range(1000):
        for b in range(c):
            for a in range(b):
                if a + b + c == 1000:
                    if a ** 2 + b ** 2 == c ** 2:
                        print a, b, c, a * b * c
                        return

func()
