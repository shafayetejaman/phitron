n = int(input())

arr = list(map(int, input().split()))

if arr == arr[::-1]:
    print("YES")
else:
    print("NO")