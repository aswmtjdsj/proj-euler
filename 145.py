import sys
#n = 1000
n = 1000000000
cnt = 0
mark = 0
for iters in range(100):
    temp_cnt = 0
    mark_ = (n / 100) * iters
    for i in range(mark, mark_):
        a = [j for j in str(i)]
        a.reverse()
        ri = int(''.join(a))
        num = i + ri
        if a[0] != '0' and len(filter(lambda x:x%2==0, map(int, [j for j in str(num)]))) == 0:
            temp_cnt += 1
        #print i, ''.join(a), num
    cnt += temp_cnt
    mark = mark_

print cnt
