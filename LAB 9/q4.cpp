#include <iostream>
#include <string>
using namespace std;

class Student {
public:
virtual double getTuition(const string& status, int creditHours) const = 0;
virtual void setResearchTopic(const string& topic) = 0;
virtual string getResearchTopic() const = 0;

};

class GraduateStudent : public Student {
string researchTopic;

public:
void setResearchTopic(const string& topic) override {
researchTopic = topic;
}

string getResearchTopic() const override {
    return researchTopic;
}

double getTuition(const string& status, int creditHours) const override {
    if (status == "undergraduate") return 200 * creditHours;
    if (status == "graduate") return 300 * creditHours;
    if (status == "doctoral") return 400 * creditHours;
    return 0;
}
};

int main() {
Student* student = new GraduateStudent();
student->setResearchTopic("Quantum Computing");

int creditHours = 15;
string status = "graduate";

cout << "Research: " << student->getResearchTopic() << endl;
cout << "Tuition (" << status << "): $" << student->getTuition(status, creditHours) << endl;

status = "doctoral";
cout << "Tuition (" << status << "): $" << student->getTuition(status, creditHours) << endl;


return 0;
}

