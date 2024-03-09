CREATE DATABASE Student_Library_Management_System

USE Student_Library_Management_System

CREATE TABLE Student (
    StudentID INT AUTO_INCREMENT PRIMARY KEY, Name VARCHAR(255) NOT NULL, Email VARCHAR(255) NOT NULL, Phone VARCHAR(15), Address TEXT
);

CREATE TABLE Book (
    ISBN VARCHAR(13) PRIMARY KEY, Title VARCHAR(255) NOT NULL, Author VARCHAR(255) NOT NULL, Genre VARCHAR(50), TotalCopies INT NOT NULL, AvailableCopies INT NOT NULL
);

CREATE TABLE Borrowing (
    BorrowID INT AUTO_INCREMENT PRIMARY KEY, StudentID INT, ISBN VARCHAR(13), BorrowDate DATE NOT NULL, DueDate DATE NOT NULL, ReturnDate DATE, FOREIGN KEY (StudentID) REFERENCES Student (StudentID), FOREIGN KEY (ISBN) REFERENCES Book (ISBN)
);

-- Inserting data into the Student table
INSERT INTO
    Student (Name, Email, Phone, Address)
VALUES (
        'John Doe', 'johndoe@example.com', '1234567890', '123 Main St'
    ),
    (
        'Jane Smith', 'janesmith@example.com', '0987654321', '456 Elm St'
    );

-- Inserting data into the Book table
INSERT INTO
    Book (
        ISBN, Title, Author, Genre, TotalCopies, AvailableCopies
    )
VALUES (
        '20', 'A Brief History of Time', 'Stephen Hawking', 'Science', 10, 100
    ),
    (
        '10', 'Introduction to Algorithms', 'Thomas H. Cormen', 'Computer Science', 5, 50
    );

-- Inserting data into the Borrowing table
INSERT INTO
    Borrowing (
        StudentID, ISBN, BorrowDate, DueDate
    )
VALUES (
        1, '1', CURDATE(), DATE_ADD(CURDATE(), INTERVAL 14 DAY)
    ),
    (
        2, '2', CURDATE(), DATE_ADD(CURDATE(), INTERVAL 14 DAY)
    );
-- Inserting more data into the Student table
INSERT INTO
    Student (Name, Email, Phone, Address)
VALUES (
        'Alice Johnson', 'alicejohnson@example.com', '1112223330', '789 Pine St'
    ),
    (
        'Bob Williams', 'bobwilliams@example.com', '4445556660', '321 Oak St'
    );

-- Inserting more data into the Book table
INSERT INTO
    Book (
        ISBN, Title, Author, Genre, TotalCopies, AvailableCopies
    )
VALUES (
        '3', 'The Art of Computer Programming', 'Donald Knuth', 'Computer Science', 7, 7
    ),
    (
        '4', 'Design Patterns: Elements of Reusable Object-Oriented Software', 'Erich Gamma', 'Software Engineering', 12, 12
    );

-- Inserting more data into the Borrowing table
INSERT INTO
    Borrowing (
        StudentID, ISBN, BorrowDate, DueDate
    )
VALUES (
        3, '3', CURDATE(), DATE_ADD(CURDATE(), INTERVAL 14 DAY)
    ),
    (
        4, '4', CURDATE(), DATE_ADD(CURDATE(), INTERVAL 14 DAY)
    );

SELECT * FROM Borrowing;

INSERT INTO
    Borrowing (
        StudentId, ISBN, BorrowDate, DueDate, ReturnDate
    )
VALUES (
        1, (
            SELECT b.ISBN
            FROM Book AS b
            ORDER BY b.AvailableCopies DESC
            LIMIT 1
        ), CURDATE(), CURDATE() + 10, CURDATE() + 20
    );

SELECT * FROM Borrowing;

UPDATE Book
SET
    AvailableCopies = AvailableCopies - 1
WHERE
    ISBN = '9781234567890';

SELECT s.Name
FROM Student AS s
    JOIN Borrowing AS b ON s.StudentID = b.StudentID
GROUP BY
    b.StudentID
HAVING
    COUNT(b.StudentID) = (
        SELECT COUNT(b.StudentID)
        FROM Student AS s
            JOIN Borrowing AS b ON s.StudentID = b.StudentID
        GROUP BY
            b.StudentID
        ORDER BY COUNT(b.StudentID) DESC
        LIMIT 1
    );

SELECT Book.Title
FROM Book
    JOIN Borrowing AS bor ON Book.ISBN = bor.ISBN
WHERE
    bor.ReturnDate < CURDATE()

USE leetcode

SELECT first_name
FROM employees
WHERE
    first_name = "King"
UNION
SELECT last_name
FROM employees
WHERE
    last_name = "King";

SELECT MIN(salary)
FROM employees
WHERE
    salary > (
        SELECT MIN(salary)
        FROM employees
    )

CREATE TABLE Employee(
    employee_id INT PRIMARY KEY,
    employee_name VARCHAR(20),
    department_id
    FOREIGN KEY (department_id) REFERENCES Department(department_id) 
    ON DELETE SET NULL
);

CREATE TABLE Department(
    department_id INT PRIMARY KEY,
    department_name VARCHAR(20)
);

CREATE TABLE JobHistory(
    employee_id INT,
    Join_date DATE,
    FOREIGN KEY (employee_id) REFERENCES Employee(employee_id) 
    ON DELETE CASCADE
);

