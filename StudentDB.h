#ifndef STUDENTDB_H
#define STUDENTDB_H

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <fstream>
using namespace std;

class Students {
public:
    int id{};
    string name{};
    int age{};
    double grade_average{};

    void input();
    void display() const;
};

void addStudents(vector<Students>& students);
void displayAll(const vector<Students>& students);
void searchStudent(vector<Students>& students);
void deleteStudent(vector<Students>& students);
void modifyStudent(vector<Students>& students);
void saveToFile(const vector<Students>& students);
void loadFromFile(vector<Students>& students);

#endif
