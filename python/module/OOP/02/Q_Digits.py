
def fun():

    n = input()

    n = n[::-1]

    for i in n:
        print(i, end=' ')
    print()


t = int(input())

for i in range(t):
    fun()
