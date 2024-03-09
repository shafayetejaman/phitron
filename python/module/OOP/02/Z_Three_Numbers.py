
a, b = map(int, input().split())

cnt = 0

for i in range(a+1):
    for j in range(a+1):
        c = b - (i + j)
        if c >= 0 and c <= a:
            cnt += 1

print(cnt)
