
x, n = map(int, input().split())


def power():
    ans = 0
    p = 2
    global n

    while n >= p:
        ans += pow(x, p)
        p += 2

    return ans


print(power())
