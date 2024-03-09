
arr1 = [[0] * 3].copy() * 3
arr2 = [[0] * 3 for _ in range(3)]

arr1[0][0] = 1
print(arr1)
print(arr2)

