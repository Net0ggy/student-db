#include "StudentDB.h"


void Students::input() {
    while (cout << "Enter ID: " && !(cin >> id))
     {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number.\n";
    } 
    cin.ignore();
    cout << "Enter name: ";
    getline(cin, name);
    while (cout << "Enter age: " && !(cin >> age)) 
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number.\n";
    }
    while (cout << "Enter Grade Average: " && !(cin >> grade_average)) 
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number.\n";
    }
}

void Students::display() const 
{
    cout << "ID: " << id
         << ", Name: " << name
         << ", Age: " << age
         << ", Grade Average: " << grade_average << "\n";
}

void addStudents(vector<Students>& students)
{
    Students s;
    s.input();
    students.push_back(s);
    saveToFile(students);
}

void displayAll(const vector<Students>& students) 
{
    for (const Students& s : students) 
    {
        s.display();
    }
}

void searchStudent(vector<Students>& students) {
    int search{};
    cout << "1.Search by ID" << "\n";
    cout << "2.Search by name" << "\n";
    cout << "3.Search by age" << "\n";
    cout << "4.Search by Grade Average" << "\n";
    cin >> search;
    bool found = false;
    if (search != 1 && search != 2 && search != 3 && search != 4)
     {
        cout << "Invalid input\n";
        return;
     }
    if (search == 1) 
    {
        int id{};
        cout << "Enter an ID" << "\n";
        cin >> id;
        for (Students& s : students) {
            if (s.id == id) {
                found = true;
                s.display();
                break;
            }
        }
    }
    if (search == 2)
    {
        string namee{};
        cout << "Enter a name" << "\n";
        while (!(getline(cin >> ws, namee)) || namee.empty()) 
        {
            cout << "Invalid input, please re-enter a non-empty name: ";
        }
        for (Students& s : students) 
        { 
            if (s.name == namee)
            
            {
                found = true;
                s.display();
                break;
            }
        }
    }
    if (search == 3) 
    {
        int age{};
        cout << "Enter an Age" << "\n";
        cin >> age;
        for (Students& s : students) 
        {
            if (s.age == age)
            {
                found = true;
                s.display();
                break;
            }
        }
    }
    if (search == 4) 
    {
        double grade_average{};
        cout << "Enter a Grade Average" << "\n";
        cin >> grade_average;
        for (Students& s : students) {
            if (s.grade_average == grade_average) 
            {
                found = true;
                s.display();
                break;
            }
        }
    }
    if (!found)
        cout << "Student not found.\n";
    saveToFile(students);
}

void deleteStudent(vector<Students>& students) 
{
    int deletee{};
    cout << "1.Delete by ID" << "\n";
    cout << "2.Delete by name" << "\n";
    cout << "3.Delete by age" << "\n";
    cout << "4.Delete by Grade Average" << "\n";
    cin >> deletee;
    if (deletee != 1 && deletee != 2 && deletee != 3 && deletee != 4) 
    {
        cout << "Invalid input\n";
        return;
    }
    bool found = false;
    if (deletee == 1) 
    {
        int id{};
        cout << "Enter an ID to delete: ";
        cin >> id;
        for (size_t i = 0; i < students.size(); ++i) 
        {
            if (students[i].id == id) 
            {
                students.erase(students.begin() + i);
                cout << "Student deleted." << "\n";
                found = true;
                break;
            }
        }
    }
    if (deletee == 2) 
    {
        string name;
        cout << "Enter name to delete: ";
        getline(cin >> ws, name);
        for (size_t i = 0; i < students.size(); ++i) 
        {
            if (students[i].name == name) 
            {
                students.erase(students.begin() + i);
                cout << "Student deleted." << "\n";
                found = true;
                break;
            }
        }
    }
    if (deletee == 3) 
    {
        int age{};
        cout << "Enter Age to delete: ";
        cin >> age;
        for (size_t i = 0; i < students.size(); ++i) 
        {
            if (students[i].age == age) 
            {
                students.erase(students.begin() + i);
                cout << "Student deleted.\n";
                found = true;
                break;
            }
        }
    }
    if (deletee == 4) 
    {
        double grade_average{};
        cout << "Enter a Grade Average to delete: ";
        cin >> grade_average;
        for (size_t i = 0; i < students.size(); ++i) 
        {
            if (students[i].grade_average == grade_average) 
            {
                students.erase(students.begin() + i);
                cout << "Student deleted.\n";
                found = true;
                break;
            }
        }
    }
    if (!found)
        cout << "Student not found.\n";
    saveToFile(students);
}

void modifyStudent(vector<Students>& students) 
{
    int modify{};
    cout << "1.Modify by ID" << "\n";
    cout << "2.Modify by name" << "\n";
    cout << "3.Modify by age" << "\n";
    cout << "4.Modify by Grade Average" << "\n";
    cin >> modify;
    bool found = false;
    if (modify != 1 && modify != 2 && modify != 3 && modify != 4) 
    {
        cout << "Invalid input\n";
        return;
    }
    if (modify == 1) 
    {
        int id{};
        cout << "Enter an ID: ";
        cin >> id;
        for (Students& s : students) 
        {
            if (s.id == id) 
            {
                int nID{};
                cout << "Enter a new ID: " << "\n";
                cin >> nID;
                s.id = nID;
                cout << "Updated successfully." << "\n";
                found = true; 
                break;
            }
        }
    }
    if (modify == 2) 
    {
        string searchName{};
        cout << "Enter the name to modify: " << "\n";
        getline(cin >> ws, searchName);
        for (Students& s : students) 
        { 
            if (s.name == searchName) 
            {
                string newName{};
                cout << "Enter new name: " << "\n";
                getline(cin >> ws, newName);
                s.name = newName;
                cout << "Updated successfully" << "\n";
                found = true;
                break;
            }
        }
    }
    if (modify == 3) 
    {
        int searchAge{};
        cout << "Enter age to modify: ";
        cin >> searchAge;
        for (Students& s : students) 
        {
            if (s.age == searchAge) 
            {
                int nAge{};
                cout << "Enter a new age: " << "\n";
                cin >> nAge;
                s.age = nAge;
                cout << "Updated successfully." << "\n";
                found = true; 
                break;
            }
        }
    }
    if (modify == 4) 
    {
        double searchGrade{};
        cout << "Enter a Grade Average to modify: ";
        cin >> searchGrade;
        for (Students& s : students) 
        {
            if (s.grade_average == searchGrade) 
            {
                double nGrade{};
                cout << "Enter a new Grade Average: " << "\n";
                cin >> nGrade;
                s.grade_average = nGrade;
                cout << "Updated successfully." << "\n";
                found = true; 
                break;
            }
        }
    }
    if (!found)
    {
        cout << "Student not found" << "\n";
    saveToFile(students);
    }
}

void saveToFile(const vector<Students>& students) 
{
    ofstream file("students.txt");
    for (const Students& s : students) 
    {
        file << s.id << '\n'
             << s.name << '\n'
             << s.age << '\n'
             << s.grade_average << '\n';
    }
    file.close();
}

void loadFromFile(vector<Students>& students) 
{
    ifstream file("students.txt");
    if (!file) return;
    Students s;
    while (file >> s.id >> ws && getline(file, s.name) && file >> s.age >> s.grade_average) 
    {
        students.push_back(s);
    }
    file.close();
}
