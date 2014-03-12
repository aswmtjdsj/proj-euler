# 1-digit * 9 -> 9
# 2-digit * 90 -> 189
# 3-digit * 900 -> 2889
# 4-digit * 9000 -> 38889
# 5-digit * 90000 -> 488889
# 6-digit * 900000 -> 5888889

d1 = 1 # 1st in 1-digit
d10 = 1 # 1st[0] in 2-digit
d100 = 5 # (100 - 9) / 2 = 45, 46th[0] in 2-digit, 46 + 9 = 55
d1000 = 3  # (1000 - 189) / 3 = 270, 271st[0]  in 3-digit, 271 + 99 = 360
d10000 = 7  # (10000 - 2889) / 4 = 1777, 1778th[2]  in 4-digit, 1778 + 999 = 2777
d100000 = 2 # (100000 - 38889) / 5 = 12222, 12223rd[0]  in 5-digit, 12223 + 9999 = 22222
d1000000 = 1 # (1000000 - 488889) / 6 = 85185, 85186th[0]  in 6-digit, 85186 + 99999 = 185185

ans = 1
total = ''.join(map(str, range(1, 1000000)))
for i in range(7):
    x = 10 ** i - 1
    digit = int(total[x])
    print digit
    ans *= digit

print ans
