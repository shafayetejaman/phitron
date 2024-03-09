n = map(int, input().split())

arr = list(map(int, input().split()))


def fun(arr):
    cnt = 0 

    while True:
        for i in range(len(arr)):
            if (arr[i] < 2 or arr[i] % 2 != 0):
                return cnt
            arr[i] /= 2
            
        cnt+=1


print(fun(arr))

