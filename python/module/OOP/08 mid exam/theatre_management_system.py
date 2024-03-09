
class Star_Cinema:

    __hall_list = []

    def _entry_hall(self, hall):

        self.__hall_list.append(hall)
        print("Entry Successful!\n")

    def _view_hall_list(self):

        print()
        for i in self.__hall_list:
            print(f"Movie Name:{i.movie_name}, ID:{i.id}, Time:{i.time}\n")


class Hall(Star_Cinema):

    def __init__(self, rows, cols, hall_no) -> None:

        self.__seats = {}
        self.__show_list = []
        self.__rows = rows
        self.__cols = cols
        self.__hall_no = hall_no

        print("Hall is created successfully!\n")

    def _entry_show(self, id, movie_name, time):
        
        self.id = id
        self.movie_name = movie_name
        self.time = time
        
        super()._entry_hall(self)

        self.__seats[id] = [[0] * self.__cols for _ in range(self.__rows)]

    def book_seats(self, id, seat):

        if (id not in self.__seats.keys() or seat[0] >= self.__rows or seat[0] < 0 or seat[1] >= self.__cols or seat[1] < 0):

            print("Invalid Entry!")
            exit(1)

        seats = self.__seats[id]

        if seats[seat[0]][seat[1]] == 1:
            print("Already Booked!")
            exit(1)

        seats[seat[0]][seat[1]] = 1

        print("The seat has been booked\n")
        self.view_available_seats(id)

    def view_show_list(self):

        super()._view_hall_list()
        print()

    def view_available_seats(self, id):

        print("All the available_seats:\n")
        for i in self.__seats[id]:
            print(i)
        print()

def main():

    cinema = Star_Cinema()

    hall = Hall(5, 5, 111)
    hall._entry_show("12", "spider man", "2/2/23 10:00 AM")
    hall._entry_show("10", "spider man 2", "2/2/23 4:00 PM")
    hall._entry_show("18", "spider man 3", "2/2/23 6:00 PM")

    while True:

        print("1:View All Show Today")
        print("2:View Available Seats")
        print("3:Book Ticket")
        print("4:Exit\n")

        option = input("Enter Option: ")

        if option == '1':

            hall.view_show_list()

        elif option == '2':

            id = input("Enter Show ID: ")
            hall.view_available_seats(id)

        elif option == '3':

            id = input("Enter Show ID: ")
            n = int(input("Number Of Ticket: "))

            for _ in range(n):

                seat = tuple(map(int, input("Enter The Row and Cols Of The Seat: ").split()))
                hall.book_seats(id, seat)
                
        else:
            break
        
    
main()