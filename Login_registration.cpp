#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

// Check whether username already exists
bool usernameExists(const string& username)
{
    ifstream file("users.txt");

    string storedUsername, storedPassword;

    while (file >> storedUsername >> storedPassword)
    {
        if (storedUsername == username)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

// Registration function
void registerUser()
{
    string username, password;

    cout << "\n===== USER REGISTRATION =====\n";

    cout << "Enter username: ";
    cin >> username;

    if (usernameExists(username))
    {
        cout << "Error: Username already exists!\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    if (username.empty() || password.empty())
    {
        cout << "Error: Username and password cannot be empty.\n";
        return;
    }

    ofstream file("users.txt", ios::app);

    if (!file)
    {
        cout << "Error: Unable to open user database.\n";
        return;
    }

    file << username << " " << password << endl;
    file.close();

    cout << "Registration successful!\n";
}

// Login function
void loginUser()
{
    string username, password;
    string storedUsername, storedPassword;

    cout << "\n========== USER LOGIN ==========\n";

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");

    if (!file)
    {
        cout << "Error: No registered users found.\n";
        return;
    }

    while (file >> storedUsername >> storedPassword)
    {
        if (storedUsername == username && storedPassword == password)
        {
            file.close();

            cout << "\nLogin successful!\n";
            cout << "Welcome, " << username << "!\n";
            return;
        }
    }

    file.close();

    cout << "\nLogin failed!\n";
    cout << "Invalid username or password.\n";
}

// Main menu
int main()
{
    int choice;

    cout << "====================================\n";
    cout << "   LOGIN & REGISTRATION SYSTEM\n";
    cout << "   CodeAlpha C++ Programming Task 2\n";
    cout << "====================================\n";

    do
    {
        cout << "\n----------- MENU -----------\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice)
        {
            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                cout << "\nThank you for using the system!\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}