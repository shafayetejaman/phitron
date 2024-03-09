def outer(i):
    print(i)

    def inner(j):
        print(j)
    # return inner

    return "12"


outer(12)(20)
