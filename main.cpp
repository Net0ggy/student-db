#include "StudentDB.h"
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <fstream>
using namespace std;


int main()
{
 vector<Students> students{};
 int choice{};
 loadFromFile(students);
 do
 {
 cout << "1.Add Student" << "\n"; 
 cout << "2.Display All" << "\n"; 
 cout << "3.Search student" << "\n";
 cout << "4.Delete student" << "\n";
 cout << "5.Modify Student" << "\n";
 cout << "6.Exit" << "\n";
 
 cin >> choice; 
 switch(choice)
 {
    case 1: addStudents(students); break;
    case 2: displayAll(students); break;
    case 3: searchStudent(students); break;
    case 4: deleteStudent(students); break;
    case 5: modifyStudent(students); break;
    case 6: cout << "Bye"; break;
    default: cout << "Invalid !"; break;
 }
}
while (choice != 6);
    return 0;
}