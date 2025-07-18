## Student CRUD Database  System in C++.
A database to manage student records.  This project implements the core CRUD operations (Create, Read, Update and Delete) along with a file I/O for data persistence and also a Search Function. 

## Features
**Add Student:** Input a student's ID, name, age, and grade average.

**Display All** Students: Show all stored student records.

**Search Student:** Search by ID, name, age, or grade average.

**Delete Student:** Remove a student record based on different criteria.

**Modify Student:** Update student details (ID, name, age, or grade average).

*All records are saved to a file (students.txt) and reloaded when the program starts.*

## File structure
├── StudentDB.h # Header file with class definitions and function prototypes.

├── StudentDB.cpp #  function definitions including file I/O implementations.

├── main.cpp # main() function and menu logic.




### Prerequisites

- A C++ compiler (e.g`g++`)
- [Visual Studio Code](https://code.visualstudio.com/) (or any text editor/IDE of your choice)
- Terminal/Command Prompt for compiling and running your code

### Installation

1. **Clone the Repository:**

   ```
   git clone https://github.com/Net0ggy/student-db.git
   cd student-db
    ````
   
   g++:
   ```
   g++ main.cpp StudentDB.cpp -o student-db
``

```
./student-db.exe



