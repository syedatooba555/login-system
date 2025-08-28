#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to register a new user
void registerUser() {
    string username, password, u, p;

    cout << "\n=== User Registration ===\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Check if username already exists
    ifstream infile("users.txt");
    while (infile >> u >> p) {
        if (u == username) {
            cout << " Username already exists. Try another.\n";
            infile.close();
            return;
        }
    }
    infile.close();

    // Save new user to file
    ofstream outfile("users.txt", ios::app);
    outfile << username << " " << password << endl;
    outfile.close();

    cout << " Registration successful!\n";
}

// Function to login user
void loginUser() {
    string username, password, u, p;
    bool found = false;

    cout << "\n=== User Login ===\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream infile("users.txt");
    while (infile >> u >> p) {
        if (u == username && p == password) {
            found = true;
            break;
        }
    }
    infile.close();

    if (found) {
        cout << " Login successful! Welcome, " << username << " \n";
    }
    else {
        cout << "Login failed! Invalid username or password.\n";
    }
}

// Main menu
int main() {
    int choice;
    do {
        cout << "\n====== LOGIN & REGISTRATION SYSTEM ======\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            loginUser();
            break;
        case 3:
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << " Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}

