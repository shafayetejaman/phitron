import csv
import os
import mysql.connector as sql
import getpass


current_path = os.path.dirname(os.path.abspath(__file__))

con_info, fields = [], []
flag = False

if not os.path.exists(f"{current_path}/DB_info.csv"):
    with open(f"{current_path}/DB_info.csv", "w", newline="\n") as file:
        file.write("host,port,user,database")
        flag = True

with open(f"{current_path}/DB_info.csv", "r", newline="\n") as file:
    rows = csv.reader(file)
    fields = next(rows)

    try:
        if not flag:
            if input("Do you want a new connection: ").lower().find("y") == 0:
                raise Exception

        con_info = next(rows)
    except:
        new_connection = []
        for i in fields:
            new_connection.append(input(f"{i}: "))
        con_info = new_connection

try:
    DB = sql.connect(
        host=con_info[0],
        port=con_info[1],
        user=con_info[2],
        database=con_info[3],
        password=getpass.getpass("Password: "),
    )
except:
    print("Unable To connect\nExiting...")
    exit(-1)

with open(f"{current_path}/DB_info.csv", "w", newline="\n") as file:
    writer = csv.writer(file)
    writer.writerows([fields] + [con_info])

if input("Do you want to disconnect: ").lower().find("y") == 0:
    if os.path.exists(f"{current_path}/DB_info.csv"):
        os.remove(f"{current_path}/DB_info.csv")
    else:
        print("The file does not exist")

cursor = DB.cursor()

cursor.execute(
    f"""
               
        select first_name from employees
        where salary > 15000   
             
"""
)

for i in cursor:
    print(i)
