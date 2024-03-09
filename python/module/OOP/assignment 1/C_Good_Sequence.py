n = input()

arr = list(map(int, input().split()))

m = {}

for i in arr:
    if i in m:
        m[i] += 1
    else:
        m[i] = 1


cnt = 0

for i in arr:
    if m[i] != i:
        cnt += 1
        m[i] -= 1

print(cnt)
