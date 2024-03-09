input()

arr = list(map(int, input().split()))

maximum = max(arr)
minimum = min(arr)

for i in arr:
    if i == maximum:
        print(minimum,end=" ")
    elif i == minimum:
        print(maximum, end=" ")
    else:
        print(i, end=" ")