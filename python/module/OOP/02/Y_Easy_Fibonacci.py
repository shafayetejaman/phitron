
n = int(input())

arr = [0, 1]

for i in range(n-2):
    arr.append(arr[-1]+arr[-2])

ans = str()
for i in arr:
    ans += str(i) + " "
    
if n == 1:
    print(0)
elif n == 2:
    print("0 1")
else:
    print(ans[:-1])
