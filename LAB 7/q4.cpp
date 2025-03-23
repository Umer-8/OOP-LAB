#include<iostream>
using namespace std;

class Person {
protected:
    string name;
    int id;
    string address;
    string phone_number;
    string email_address;

public:
    Person(string name, string address, string phone_number, string email_address, int id)
        : name(name), id(id), address(address), phone_number(phone_number), email_address(email_address) {}

    virtual void displayInfo() {
        cout << "Name-" << name << endl;
        cout << "ID-" << id << endl;
        cout << "Address-" << address << endl;
        cout << "Email Address-" << email_address << endl;
        cout << "Phone Number-" << phone_number << endl;
    }

    virtual void updateInfo() {
        cout << "Enter new ID:" << endl;
        cin >> id;
        cout << "Enter new email address:" << endl;
        cin >> email_address;
    }
};

class Student : public Person {
private:
    double gpa;
    string enrollment_year;
    string* courses_included;
    int num_courses;
    int course_count;

public:
    Student(string name, string address, string phone_number, string email_address, int id, int num_courses, double gpa, string enrollment_year)
        : Person(name, address, phone_number, email_address, id), gpa(gpa), enrollment_year(enrollment_year), num_courses(num_courses), course_count(0) {
        courses_included = new string[num_courses];
        for (int i = 0; i < num_courses; i++) {
            cout << "Enter course " << i + 1 << ":" << endl;
            cin >> courses_included[i];
        }
    }

    int getID() {
        return id;
    }

    int getnumcourses() {
        return num_courses;
    }

    void addCourse(const string& courseName) {
        if (course_count < num_courses) {
            courses_included[course_count] = courseName;
            course_count++;
            cout << "Course " << courseName << " added to student " << id << endl;
        } else {
            cout << "No space to add more courses for student " << id << endl;
        }
    }

    void displayInfo() override {
        cout << "Student Information." << endl;
        Person::displayInfo();
        cout << "GPA-" << gpa << endl;
        cout << "Enrollment Year-" << enrollment_year << endl;
        cout << "Courses:" << endl;
        for (int i = 0; i < course_count; i++) {
            cout << courses_included[i] << endl;
        }
    }

    ~Student() {
        delete[] courses_included;
    }
};

class Professor : public Person {
private:
    string department_name;
    int num_courses;
    string* courses_taught;
    int salary;
    int num_professors;

public:
    Professor(string name, string address, string phone_number, string email_address, int id, int num_courses, string department_name, int num_professors)
        : num_courses(num_courses), department_name(department_name), num_professors(num_professors), Person(name, address, phone_number, email_address, id) {
        courses_taught = new string[num_courses];
        for (int i = 0; i < num_courses; i++) {
            cout << "Enter course " << i + 1 << ":" << endl;
            cin >> courses_taught[i];
        }
    }

    void displayInfo() override {
        cout << "Profeesors Information." << endl;
        Person::displayInfo();
        cout << "Department Name-" << department_name << endl;
        cout << "Salary-" << salary << endl;
        cout << "Courses:" << endl;
        for (int i = 0; i < num_courses; i++) {
            cout << courses_taught[i] << endl;
        }
    }

    void updateInfo() override {
        int ID;
        cout << "Enter ID:" << endl;
        cin >> ID;
        for (int i = 0; i < num_professors; i++) {
            if (ID == id) {
                Person::updateInfo();
            }
        }
    }

    ~Professor() {
        delete[] courses_taught;
    }
};

class Staff : public Person {
private:
    string department_name;
    string position;
    int salary;
    int num_staff;

public:
    Staff(string name, string address, string phone_number, string email_address, int id, string department_name, string position, int salary, int num_staff)
        : department_name(department_name), position(position), salary(salary), num_staff(num_staff), Person(name, address, phone_number, email_address, id) {}

    void displayInfo() override {
        cout << "Staff Information." << endl;
        Person::displayInfo();
        cout << "Department Name-" << department_name << endl;
        cout << "Position-" << position << endl;
        cout << "Salary-" << salary << endl;
    }

    void updateInfo() override {
        int ID;
        cout << "Enter ID:" << endl;
        cin >> ID;
        for (int i = 0; i < num_staff; i++) {
            if (ID == id) {
                Person::updateInfo();
            }
        }
    }
};

class Course {
private:
    int courseID;
    string course_name;
    int credits;
    string instructor_name;
    Student** s;
    int num_students;
    int student_count;

public:
    Course(int id, string course_name, int credits, string instructor_name, int num_students)
        : courseID(id), course_name(course_name), credits(credits), instructor_name(instructor_name), num_students(num_students), student_count(0) {
        s = new Student*[num_students];
    }

    ~Course() 
    {
        delete[] s;
    }

    void registerStudent(Student* student)
     {
        if (student_count < num_students) {
            s[student_count] = student;
            student_count++;
            student->addCourse(course_name);
            cout << "Student " << student->getID() << " registered for course " << course_name << endl;
        } else {
            cout << "Course " << course_name << " is full. Cannot register more students." << endl;
        }
    }

    void calculateGrades() {
        int ID;
        cout << "Enter Student ID: ";
        cin >> ID;

        for (int i = 0; i < student_count; i++) {
            if (s[i]->getID() == ID) {
                int midMarks, finalMarks;
                cout << "Enter Mid Marks: ";
                cin >> midMarks;
                cout << "Enter Final Marks: ";
                cin >> finalMarks;

                int grade = midMarks + finalMarks;
                cout << "Grade: " << grade << endl;
                return;
            }
        }

        cout << "Student with ID " << ID << " not found in this course." << endl;
    }
};

int main() {
    int num_students = 1;
    Student** s = new Student*[num_students];

    cout << "FOR STUDENTS:" << endl;
    for (int i = 0; i < num_students; i++) {
        string name, address, phone_number, email_address, enrollment_year;
        int id, num_courses;
        double gpa;

        cout << "Enter name: ";
        cin >> name;
        cout << "Enter address: ";
        cin >> address;
        cout << "Enter phone number: ";
        cin >> phone_number;
        cout << "Enter email address: ";
        cin >> email_address;
        cout << "Enter id: ";
        cin >> id;
        cout << "Enter number of courses: ";
        cin >> num_courses;
        cout << "Enter gpa: ";
        cin >> gpa;
        cout << "Enter enrollment year: ";
        cin >> enrollment_year;

        s[i] = new Student(name, address, phone_number, email_address, id, num_courses, gpa, enrollment_year);
    }

    int num_professors = 1;
    Professor** p = new Professor*[num_professors];
    cout << "FOR PROFESSORS:" << endl;
    for (int i = 0; i < num_professors; i++) {
        string name, address, phone_number, email_address, department_name;
        int id, num_proffcourses;

        cout << "Enter name: ";
        cin >> name;
        cout << "Enter address: ";
        cin >> address;
        cout << "Enter phone number: ";
        cin >> phone_number;
        cout << "Enter email address: ";
        cin >> email_address;
        cout << "Enter id: ";
        cin >> id;
        cout << "Enter number of courses: ";
        cin >> num_proffcourses;
        cout << "Enter department name: ";
        cin >> department_name;
        p[i] = new Professor(name, address, phone_number, email_address, id, num_proffcourses, department_name, num_professors);
    }

    int num_staff = 1;
    Staff** z = new Staff*[num_staff];
    cout << "FOR STAFF:" << endl;
    for (int i = 0; i < num_staff; i++) {
        string department_name, position, name, address, phone_number, email_address;
        int salary, id;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter address: ";
        cin >> address;
        cout << "Enter phone number: ";
        cin >> phone_number;
        cout << "Enter email address: ";
        cin >> email_address;
        cout << "Enter id: ";
        cin >> id;
        cout << "Enter department name: ";
        cin >> department_name;
        cout << "Enter position: ";
        cin >> position;
        cout << "Enter salary: ";
        cin >> salary;

        z[i] = new Staff(name, address, phone_number, email_address, id, department_name, position, salary, num_staff);
    }

    int num_courses = 1;
    Course** c = new Course*[num_courses];

    for (int i = 0; i < num_courses; i++) {
        int courseID, credits;
        string course_name, instructor_name;

        cout << "Enter courseID: ";
        cin >> courseID;
        cout << "Enter credits: ";
        cin >> credits;
        cout << "Enter course name: ";
        cin >> course_name;
        cout << "Enter instructor name: ";
        cin >> instructor_name;

        c[i] = new Course(courseID, course_name, credits, instructor_name, num_students);
    }

    Person* x;

    for (int i = 0; i < num_students; i++) {
        x = s[i];
        x->displayInfo();
        x->updateInfo();
    }
    for (int i = 0; i < num_professors; i++) {
        x = p[i];
        x->displayInfo();
        x->updateInfo();
    }
    for (int i = 0; i < num_staff; i++) {
        x = z[i];
        x->displayInfo();
        x->updateInfo();
    }

    for (int i = 0; i < num_courses; i++) {
        for (int j = 0; j < num_students; j++) {
            c[i]->registerStudent(s[j]);
        }
    }

    for (int i = 0; i < num_courses; i++) {
        c[i]->calculateGrades();
    }

    for (int i = 0; i < num_students; i++) {
        delete s[i];
    }
    for (int i = 0; i < num_professors; i++) {
        delete p[i];
    }
    for (int i = 0; i < num_staff; i++) {
        delete z[i];
    }
    for (int i = 0; i < num_courses; i++) {
        delete c[i];
    }

    delete[] s;
    delete[] p;
    delete[] z;
    delete[] c;

    return 0;
}