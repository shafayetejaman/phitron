n, q = map(int, input().split())

arr = list(map(int, input().split()))

prefix = [0]

for i in arr:
    
    prefix.append(prefix[-1] + i)
    

for _ in range(q):

    l, r = map(int, input().split())

    sum = prefix[r] - prefix[l-1]

    print(sum)
