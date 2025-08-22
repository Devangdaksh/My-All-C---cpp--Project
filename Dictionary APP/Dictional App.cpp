#include <iostream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

class Dictionary {
private:
    map<string, string> dictionary;

public:
    // Function to add a word and its definition
    void addWord(const string& word, const string& definition) {
        dictionary[word] = definition;
        cout << "Word added successfully!" << endl;
    }

    // Function to search for a word
    void searchWord(const string& word) {
        auto it = dictionary.find(word);
        if (it != dictionary.end()) {
            cout << "Definition of " << word << ": " << it->second << endl;
        } else {
            cout << "Word not found!" << endl;
        }
    }

    // Function to delete a word
    void deleteWord(const string& word) {
        auto it = dictionary.find(word);
        if (it != dictionary.end()) {
            dictionary.erase(it);
            cout << "Word deleted successfully!" << endl;
        } else {
            cout << "Word not found!" << endl;
        }
    }

    // Function to display all words
    void displayAllWords() {
        if (dictionary.empty()) {
            cout << "No words in the dictionary!" << endl;
        } else {
            cout << "\n--- Dictionary ---\n";
            for (const auto& entry : dictionary) {
                cout << entry.first << ": " << entry.second << endl;
            }
        }
    }
};

// Function to display the menu
void displayMenu() {
    cout << "\n--- Dictionary App ---\n";
    cout << "1. Add a Word\n";
    cout << "2. Search for a Word\n";
    cout << "3. Delete a Word\n";
    cout << "4. Display All Words\n";
    cout << "5. Exit\n";
    cout << "-----------------------\n";
    cout << "Enter your choice: ";
}

int main() {
    Dictionary dict;
    int choice;
    string word, definition;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the word: ";
            cin.ignore();  // to clear the input buffer
            getline(cin, word);
            cout << "Enter the definition: ";
            getline(cin, definition);
            dict.addWord(word, definition);
            break;
        case 2:
            cout << "Enter the word to search: ";
            cin.ignore();
            getline(cin, word);
            dict.searchWord(word);
            break;
        case 3:
            cout << "Enter the word to delete: ";
            cin.ignore();
            getline(cin, word);
            dict.deleteWord(word);
            break;
        case 4:
            dict.displayAllWords();
            break;
        case 5:
            cout << "Exiting the dictionary app...\n";
            return 0;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
