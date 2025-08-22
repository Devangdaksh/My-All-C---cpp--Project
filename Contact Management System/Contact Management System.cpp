
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Contact {
public:
    string name;
    string phoneNumber;
    string email;

    // Constructor to initialize a new contact
    Contact(string name, string phoneNumber, string email) {
        this->name = name;
        this->phoneNumber = phoneNumber;
        this->email = email;
    }

    // Function to display contact details
    void displayContact() {
        cout << "Name: " << name << ", Phone: " << phoneNumber << ", Email: " << email << endl;
    }
};

class ContactManager {
private:
    vector<Contact> contacts;

public:
    // Add a new contact
    void addContact(string name, string phoneNumber, string email) {
        contacts.push_back(Contact(name, phoneNumber, email));
    }

    // Display all contacts
    void displayContacts() {
        if (contacts.empty()) {
            cout << "No contacts available!" << endl;
            return;
        }
        for (int i = 0; i < contacts.size(); i++) {
            contacts[i].displayContact();
        }
    }

    // Search for a contact by name
    void searchContact(string name) {
        bool found = false;
        for (int i = 0; i < contacts.size(); i++) {
            if (contacts[i].name == name) {
                contacts[i].displayContact();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Contact not found!" << endl;
        }
    }

    // Update a contact's details
    void updateContact(string name, string newPhoneNumber, string newEmail) {
        for (int i = 0; i < contacts.size(); i++) {
            if (contacts[i].name == name) {
                contacts[i].phoneNumber = newPhoneNumber;
                contacts[i].email = newEmail;
                cout << "Contact updated successfully!" << endl;
                return;
            }
        }
        cout << "Contact not found!" << endl;
    }

    // Delete a contact by name
    void deleteContact(string name) {
        for (int i = 0; i < contacts.size(); i++) {
            if (contacts[i].name == name) {
                contacts.erase(contacts.begin() + i);
                cout << "Contact deleted successfully!" << endl;
                return;
            }
        }
        cout << "Contact not found!" << endl;
    }
};

// Function to display the menu options
void displayMenu() {
    cout << "\n--- Contact Management System ---\n";
    cout << "1. Add Contact\n";
    cout << "2. Display Contacts\n";
    cout << "3. Search Contact\n";
    cout << "4. Update Contact\n";
    cout << "5. Delete Contact\n";
    cout << "6. Exit\n";
    cout << "-----------------------------------\n";
    cout << "Choose an option: ";
}

int main() {
    ContactManager cm;
    int choice;
    string name, phoneNumber, email;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter name: ";
            cin.ignore();  // Ignore any leftover newline character
            getline(cin, name);
            cout << "Enter phone number: ";
            getline(cin, phoneNumber);
            cout << "Enter email: ";
            getline(cin, email);
            cm.addContact(name, phoneNumber, email);
            break;
        case 2:
            cm.displayContacts();
            break;
        case 3:
            cout << "Enter name to search: ";
            cin.ignore();  // Ignore any leftover newline character
            getline(cin, name);
            cm.searchContact(name);
            break;
        case 4:
            cout << "Enter name to update: ";
            cin.ignore();  // Ignore any leftover newline character
            getline(cin, name);
            cout << "Enter new phone number: ";
            getline(cin, phoneNumber);
            cout << "Enter new email: ";
            getline(cin, email);
            cm.updateContact(name, phoneNumber, email);
            break;
        case 5:
            cout << "Enter name to delete: ";
            cin.ignore();  // Ignore any leftover newline character
            getline(cin, name);
            cm.deleteContact(name);
            break;
        case 6:
            cout << "Exiting program...\n";
            return 0;
        default:
            cout << "Invalid option! Try again.\n";
        }
    }

    return 0;
}