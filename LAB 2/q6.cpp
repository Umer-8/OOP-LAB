#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Subject {
    string subject_name;
};

struct Student {
    int ID;
    vector<Subject> subjects;
};

void addSubject(Student &student, string subject_name) {
    student.subjects.push_back({subject_name});   
}

void printStudentInfo(Student &student) {
    cout << "Student ID: " << student.ID << endl;
    cout << "Subjects:" << endl;
    for (int i = 0; i < 2; i++) {
        cout << student.subjects[i].subject_name << endl;
    }
}

int main() {
    Student student;
    student.ID = 1;

    addSubject(student, "Math");
    addSubject(student, "Physics");

    printStudentInfo(student);

    return 0;
}
