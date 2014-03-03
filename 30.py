# 9 ** 5 * 10 = 590490
# 9 ** 5 * 6 = 354294

a = []
for i in range(2, 354295):
    if sum(map(lambda x: x**5, map(int, [j for j in str(i)]))) == i:
        a.append(i)

print a
print sum(a)
