#include <iostream>
#include <string>
using namespace std;

class String {
    string s;
public:
    String(const string &str) : s(str) {}

    String operator+(const string &s1) {
        return String(s + s1);
    }

    String &operator=(const string &s1) {
        s = s1; // Corrected: removed 'st'
        return *this;
    }

    bool operator<=(const string &s1) {
        return s <= s1;
    }

    void display() const {
        cout << "\nString stored in class = " << s;
    }

    void displayLength() const {
        cout << "\nLength of string stored in class = " << s.length();
    }

    void toLower() {
        cout << "\nString converted to lowercase";
        for (char &c : s) {
            c = tolower(c);
        }
        display();
    }

    void toUpper() {
        cout << "\nString converted to uppercase";
        for (char &c : s) {
            c = toupper(c);
        }
        display();
    }
};

int main() {
    string s1;
    int choice;

    cout <<"Program to perform operations on string\n";
    cout << "Enter string to be stored in class: ";
    getline(cin, s1);

    String s(s1);
    cout << "Menu\n 1. String concatenation \n 2. String copy \n 3. String comparison \n 4.Display String \n 5. Display length of string \n 6. Convert string to lowercase \n 7. Convert string touppercase \n 8. Exit ";
    while (true) {
        string d;
        cout<<"\nenter your choice:";
        cin >> choice;
        cin.ignore(); // to clear the newline character left by cin

        if (choice == 1) {
            cout << "\nEnter the string to concatenate: ";
            getline(cin, d);
            s = s + d;
            cout << "\n After concatenation....";
            s.display();
        } 
        else if (choice == 2) {
            cout << "\nEnter the string to copy: ";
            getline(cin, d);
            s = d;
            cout << "\n After copying....";
            s.display();
        } 
        else if (choice == 3) {
            cout << "Enter the string to compare: ";
            getline(cin, d);
            if (s <= d) {
                cout << "\nStrings are equal or first is lexicographically smaller";
            } else {
                cout << "\nFirst string is lexicographically greater";
            }
        } 
        else if (choice == 4) {
            s.display();
        }
        
        else if (choice == 5) {
            s.displayLength();
        } 
        else if (choice == 6) {
            s.toLower();
        } 
        else if (choice == 7) {
            s.toUpper();
        } 
        else if (choice == 8) {
            break;
        } 
        else {
            cout << "Wrong choice";
        }
    }

    return 0;
}
