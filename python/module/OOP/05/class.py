class Dog:

    kind = 'canine'         # class variable shared by all instances

    def __init__(self, name):
        self.name = name    # instance variable unique to each instance
    
    def fun(self, id):
        self.id = id
        return self.name

d = Dog('Fido')
e = Dog('Buddy')

print(d.kind)                  # shared by all dogs

print(e.kind)                  # shared by all dogs

print(d.name)                  # unique to d

print(e.fun("12"))                  # unique to e
