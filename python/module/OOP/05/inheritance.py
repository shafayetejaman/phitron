class School:
    def __init__(self, school) -> None:
        self.school = school


class Work:
    def __init__(self, job) -> None:
        self.job = job


class Student(School):
    def __init__(self, name, school) -> None:
        self.name = name
        School.__init__(self, school)
        # Work.__init__(self, job)


akash = Student("akash", "fcub")

print(akash.name, akash.school)
