
def count(a, b):

    sum = 0
    
    if (a > b):
        a,b = b,a

    for i in range(a+1, b):
        if (i % 2 == 1):
            sum += i

    return sum


t = int(input())

while (t):
    a, b = map(int, input().split())
    ans = count(a, b)
    print(ans)
    t -= 1
