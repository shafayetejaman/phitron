arr = list(map(str, input().split()))

s = str()

for i in arr:
    s += i[::-1] + " "

print(s[:-1])
