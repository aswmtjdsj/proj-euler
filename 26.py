from p26 import func

ans = 0
ans_ = 1
for i in range(1, 1000):
    temp = ans
    ans = max(ans, func(1, i))
    if ans > temp:
        ans_ = i

print ans, ans_
