#include <iostream>
using namespace std;

int main() {
    const int MAX_EMPLOYEES = 10;
    const int NAME_LENGTH = 10;
    const int POSITION_LENGTH = 10;  
    const int PHONE_LENGTH = 10;
    
    string names[MAX_EMPLOYEES];
    string positions[MAX_EMPLOYEES];
    string phoneNumbers[MAX_EMPLOYEES];
    int ids[MAX_EMPLOYEES];
    int ages[MAX_EMPLOYEES];
    double salaries[MAX_EMPLOYEES];
    int count = 0;

    while (true) {
        cout << "\nEmployee Management System\n";
        cout << "1. Add Employee\n";
        cout << "2. View All Employees\n";
        cout << "3. Search Employee\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            if (count >= MAX_EMPLOYEES) {
                cout << "Maximum employees reached!\n";
                continue;
            }

            // Name input (max 10 characters)
            cout << "Enter employee name (max 10 chars): ";
            string name;
            cin >> name;
            if (name.length() > NAME_LENGTH) {
                cout << "Name too long! Using first 10 characters.\n";
                name = name.substr(0, NAME_LENGTH);
            }
            names[count] = name;

            // Position input (now max 20 characters)
            cout << "Enter employee position (max 10 chars): ";
            string position;
            cin >> position;
            if (position.length() > POSITION_LENGTH) {
                cout << "Position too long! please try again.\n";
                cin>>position;
            }
            positions[count] = position;
            
            cout << "Enter employee ID: ";
            cin >> ids[count];

            // Phone number input (exactly 10 digits)
            cout << "Enter employee phone number (10 digits): ";
            string phone;
            cin >> phone;
            while (phone.length() != PHONE_LENGTH) {
                cout << "Invalid length! Enter exactly 10 digits: ";
                cin >> phone;
            }
            phoneNumbers[count] = phone;

            cout << "Enter employee age: ";
            cin >> ages[count];
            
            cout << "Enter employee salary: ";
            cin >> salaries[count];
            
            count++;
            cout << "Employee added successfully!\n";

        } else if (choice == 2) {
            if (count == 0) {
                cout << "No employees in the system.\n";
                continue;
            }

            cout << "\nEmployee List:\n";
            cout << "ID\tName\t\tPosition\t\t\tPhone\t\tAge\tSalary\n";
            cout << "-------------------------------------------------------------------------\n";
            for (int i = 0; i < count; i++) {
                cout << ids[i] << "\t" 
                     << names[i] << "\t";
                if (names[i].length() < 8) cout << "\t";
                cout << positions[i] << "\t";
                if (positions[i].length() < 16) cout << "\t";
                cout << phoneNumbers[i] << "\t" 
                     << ages[i] << "\t$" 
                     << salaries[i] << "\n";
            }

        } else if (choice == 3) {
            /* ... rest of the search code remains exactly the same ... */
        } else if (choice == 4) {
            cout << "Exiting the system. Goodbye!\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}