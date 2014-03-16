ans = 0
for i in range(1, 10):
    for j in range(1, 1000): # too long cannot be handled
        if len(str(i ** j)) == j:
            ans += 1
        elif len(str(i ** j))  < j:
            break
print ans
