#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Employee {
private:
    int id;
    string name;
    string designation;
    int yearsOfService;

public:
    Employee(int id = 0, string name = "", string designation = "", int years = 0)
        : id(id), name(name), designation(designation), yearsOfService(years) {}

    int getId() const { return id; }
    string getName() const { return name; }
    string getDesignation() const { return designation; }
    int getYearsOfService() const { return yearsOfService; }

    void setId(int newId) { id = newId; }
    void setName(const string& newName) { name = newName; }
    void setDesignation(const string& newDesignation) { designation = newDesignation; }
    void setYearsOfService(int years) { yearsOfService = years; }

    void display() const {
        cout << "ID: " << id 
             << ", Name: " << name 
             << ", Designation: " << designation 
             << ", Years: " << yearsOfService << endl;
    }

    string serialize() const {
        return to_string(id) + "|" + name + "|" + designation + "|" + to_string(yearsOfService);
    }

    void deserialize(const string& data) {
        size_t pos1 = data.find('|');
        id = stoi(data.substr(0, pos1));
        
        size_t pos2 = data.find('|', pos1 + 1);
        name = data.substr(pos1 + 1, pos2 - pos1 - 1);
        
        size_t pos3 = data.find('|', pos2 + 1);
        designation = data.substr(pos2 + 1, pos3 - pos2 - 1);
        
        yearsOfService = stoi(data.substr(pos3 + 1));
    }
};

const string FILENAME = "q2.txt";

void writeAllEmployees(const vector<Employee>& employees);

void createDummyData() {
    vector<Employee> dummyEmployees;
    dummyEmployees.emplace_back(1, "John Doe", "Manager", 3);
    dummyEmployees.emplace_back(2, "Jane Smith", "Developer", 1);
    dummyEmployees.emplace_back(3, "Mike Johnson", "Manager", 5);
    dummyEmployees.emplace_back(4, "Sarah Williams", "Designer", 2);
    dummyEmployees.emplace_back(5, "David Brown", "Manager", 2);
    dummyEmployees.emplace_back(6, "Emily Davis", "Tester", 1);
    writeAllEmployees(dummyEmployees);
}

vector<Employee> readAllEmployees() {
    vector<Employee> employees;
    ifstream file(FILENAME);
    string line;
    
    while (getline(file, line)) {
        Employee emp;
        emp.deserialize(line);
        employees.push_back(emp);
    }
    
    file.close();
    return employees;
}

void writeAllEmployees(const vector<Employee>& employees) {
    ofstream file(FILENAME);
    
    for (const auto& emp : employees) {
        file << emp.serialize() << "\n";
    }
    
    file.close();
}

vector<Employee> findManagersWithMinYears(int minYears) {
    vector<Employee> allEmployees = readAllEmployees();
    vector<Employee> result;
    
    for (const auto& emp : allEmployees) {
        if (emp.getDesignation() == "Manager" && emp.getYearsOfService() >= minYears) {
            result.push_back(emp);
        }
    }
    
    return result;
}

void deleteAllExcept(const vector<Employee>& toKeep) {
    writeAllEmployees(toKeep);
}

void duplicateWithIncrementedIdsAndYears(const vector<Employee>& source) {
    vector<Employee> currentEmployees = readAllEmployees();
    int maxId = 0;
    
    for (const auto& emp : currentEmployees) {
        if (emp.getId() > maxId) {
            maxId = emp.getId();
        }
    }
    
    for (const auto& emp : source) {
        Employee newEmp = emp;
        newEmp.setId(++maxId);
        newEmp.setYearsOfService(emp.getYearsOfService() + 1);
        currentEmployees.push_back(newEmp);
    }
    
    writeAllEmployees(currentEmployees);
}

int main() {
    createDummyData();
    
    cout << "\nQuery a) Managers with at least 2 years of service:\n";
    vector<Employee> managers = findManagersWithMinYears(2);
    for (const auto& emp : managers) {
        emp.display();
    }
    
    deleteAllExcept(managers);
    cout << "\nAfter deletion (remaining employees):\n";
    vector<Employee> remaining = readAllEmployees();
    for (const auto& emp : remaining) {
        emp.display();
    }
    
    duplicateWithIncrementedIdsAndYears(managers);
    cout << "\nAfter duplication (all employees):\n";
    vector<Employee> finalEmployees = readAllEmployees();
    for (const auto& emp : finalEmployees) {
        emp.display();
    }
    
    return 0;
}