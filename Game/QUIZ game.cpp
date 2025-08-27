#include <iostream>
#include <string>
using namespace std;

struct Question {
    string text;
    string options[4];
    int correct;
};

int main() {
    Question questions[5] = {
        {"Which C++ feature enables bundling data with functions?",
         {"Inheritance","Polymorphism","Encapsulation","Abstraction"}, 3},

        {"Which keyword defines a class method that cannot be overridden?",
         {"override","final","static","virtual"}, 2},

        {"Which function is called when an object goes out of scope?",
         {"Constructor","Destructor","Allocator","Deleter"}, 2},

        {"Which C++ feature provides type-safe generic code?",
         {"Macros","Templates","typedef","using"}, 2},

        {"Which operator cannot be overloaded?",
         {"()","[]","?:","->"}, 3}
    };

    int score = 0;

    cout << "OOP/C++ Quiz - Answer using numbers 1..4\n";

    for (int i = 0; i < 5; i++) {
        cout << "\nQ" << (i+1) << ": " << questions[i].text << endl;
        for (int j = 0; j < 4; j++) {
            cout << "  " << (j+1) << ") " << questions[i].options[j] << endl;
        }

        int ans;
        cout << "Your answer (1-4): ";
        cin >> ans;

        if (ans == questions[i].correct) {
            cout << "Correct!\n";
            score++;
        } else {
            cout << "Wrong. Correct answer: "
                 << questions[i].correct << ") "
                 << questions[i].options[questions[i].correct-1] << endl;
        }
    }

    cout << "\nFinal Score: " << score << " / 5\n";
    if (score == 5) cout << "Excellent!\n";
    else if (score >= 3) cout << "Good job!\n";
    else cout << "Keep practicing.\n";

    return 0;
}
