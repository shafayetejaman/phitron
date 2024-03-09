
def sum(*args):
    n = 0
    for i in args:
        n += i
    return n


print(sum(1, 2, 3))


def detail(**kwargs):
    for name, age in kwargs.items():
        print(f"name = {name}, age = {age}")


detail(akash=22, sakib=23)
