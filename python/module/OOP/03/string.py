
nums = [3, 4, 5, 1, 12, 14, 13]

sum = nums[0]

m = {}
l = 0

for i, n in enumerate(nums):
    if i == 0:
        continue

    if nums[i-1] == n+1:
        sum += n
    else:
        m[i-l] = sum
        l = i
        sum = n
        
maximum = max(m.keys())

for i in 
        
     

