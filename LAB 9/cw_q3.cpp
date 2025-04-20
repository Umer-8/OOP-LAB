#include <iostream>
#include <vector>
#include <string>

using namespace std;

class PatientRecord {
private:
    string name;
    string id;
    string dob;
    vector<string> medicalHistory;
    vector<string> treatments;
    vector<string> billingServices;
    vector<double> billingCosts;

    friend class Doctor;
    friend class BillingStaff;

public:
    PatientRecord(string n, string i, string d) : name(n), id(i), dob(d) {}

    void displayPublicInfo() {
        cout << "Patient: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "DOB: " << dob << endl;
    }
};

class Doctor {
public:
    static void addMedicalEntry(PatientRecord& p, string entry) {
        p.medicalHistory.push_back(entry);
        cout << "Added medical entry: " << entry << endl;
    }

    static void addTreatment(PatientRecord& p, string treatment) {
        p.treatments.push_back(treatment);
        cout << "Added treatment: " << treatment << endl;
    }

    static void displayMedicalData(PatientRecord& p) {
        cout << "\nMedical History:\n";
        for (auto& entry : p.medicalHistory)
            cout << "- " << entry << endl;
        
        cout << "\nCurrent Treatments:\n";
        for (auto& treatment : p.treatments)
            cout << "- " << treatment << endl;
    }
};

class BillingStaff {
public:
    static void addBilling(PatientRecord& p, string service, double cost) {
        p.billingServices.push_back(service);
        p.billingCosts.push_back(cost);
        cout << "Added billing: " << service << " ($" << cost << ")\n";
    }

    static void displayBillingData(PatientRecord& p) {
        cout << "\nBilling Records:\n";
        for (size_t i = 0; i < p.billingServices.size(); i++) {
            cout << "- " << p.billingServices[i] << ": $" << p.billingCosts[i] << endl;
        }
    }
};

class Receptionist {
public:
    static void displayPatientInfo(PatientRecord& p) {
        cout << "\nPatient Information:\n";
        p.displayPublicInfo();
    }
};

int main() {
    PatientRecord patient("John Doe", "P1001", "1985-05-15");

    cout << " Doctor Access " << endl;
    Doctor::addMedicalEntry(patient, "Diagnosed with hypertension");
    Doctor::addTreatment(patient, "Lisinopril 10mg daily");
    Doctor::displayMedicalData(patient);

    cout << " Billing Staff Access " << endl;
    BillingStaff::addBilling(patient, "Annual Checkup", 150.0);
    BillingStaff::addBilling(patient, "Blood Test", 75.5);
    BillingStaff::displayBillingData(patient);

    cout << " Receptionist Access " << endl;
    Receptionist::displayPatientInfo(patient);

    return 0;
}