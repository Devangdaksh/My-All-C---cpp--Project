#include <iostream>
#include <vector>
using namespace std;

class Patient {
public:
    int id;
    string name;
    int age;
    string disease;

    Patient(int i, string n, int a, string d) {
        id = i;
        name = n;
        age = a;
        disease = d;
    }
};

class Hospital {
private:
    vector<Patient> patients;
public:
    void admitPatient() {
        int id, age;
        string name, disease;
        cout << "Enter Patient ID: ";
        cin >> id;
        cout << "Enter Patient Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Disease: ";
        cin.ignore();
        getline(cin, disease);
        Patient p(id, name, age, disease);
        patients.push_back(p);
        cout << "Patient admitted successfully.\n";
    }

    void searchPatient(int id) {
        for(const Patient &p : patients) {
            if(p.id == id) {
                cout << "Patient found:\n";
                cout << "ID: " << p.id << "\nName: " << p.name << "\nAge: " << p.age << "\nDisease: " << p.disease << endl;
                return;
            }
        }
        cout << "Patient not found.\n";
    }

    void displayPatients() {
        if(patients.empty()) {
            cout << "No patients admitted yet.\n";
            return;
        }
        cout << "\nList of Patients:\n";
        for(const Patient &p : patients) {
            cout << "ID: " << p.id << " | Name: " << p.name << " | Age: " << p.age << " | Disease: " << p.disease << endl;
        }
    }
};

int main() {
    Hospital hospital;
    int choice;
    do {
        cout << "\nHospital Management System Menu:\n";
        cout << "1. Admit Patient\n";
        cout << "2. Search Patient by ID\n";
        cout << "3. Display All Patients\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                hospital.admitPatient();
                break;
            case 2: {
                int id;
                cout << "Enter Patient ID to search: ";
                cin >> id;
                hospital.searchPatient(id);
                break;
            }
            case 3:
                hospital.displayPatients();
                break;
            case 4:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != 4);

    return 0;
}
