
s = input()

cnt = 0
ans = []
temp = str()

for i in s:
    if i == 'L': cnt+=1
    else: cnt-=1
    
    temp += i
    
    if cnt == 0:
        ans.append(temp)
        temp = ''
 
print(len(ans))  

for i in ans:
    print(i)    

