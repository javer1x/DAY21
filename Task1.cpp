#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 100;

// Declare arrays for student records
string names[MAX_STUDENTS];
int ids[MAX_STUDENTS];
string grades[MAX_STUDENTS];
int currentSize = 0;

// Function prototypes
void addStudent();
void viewRecords();
void updateGrade();
void searchStudent();
void showMenu();

int main() {
    int choice;
    
    do {
        showMenu();
        cin >> choice;
        
        cin.ignore();
        
        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewRecords();
                break;
            case 3:
                updateGrade();
                break;
            case 4:
                searchStudent();
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

void showMenu() {
    cout << "\nStudent Record Management System" << endl;
    cout << "1. Add New Student Record" << endl;
    cout << "2. View All Records" << endl;
    cout << "3. Update Student Grade" << endl;
    cout << "4. Search for Student by ID" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

void addStudent() {
    if (currentSize >= MAX_STUDENTS) {
        cout << "Record limit reached. Cannot add more students." << endl;
        return;
    }

    cout << "Enter student name: ";
    getline(cin, names[currentSize]);
    
    cout << "Enter student ID: ";
    cin >> ids[currentSize];
    
    cout << "Enter student grade: ";
    cin >> grades[currentSize];
    
    cin.ignore();
    
    currentSize++;
    cout << "Student record added successfully." << endl;
}

void viewRecords() {
    if (currentSize == 0) {
        cout << "No records available." << endl;
        return;
    }

    cout << "\nStudent Records:" << endl;
    for (int i = 0; i < currentSize; ++i) {
        cout << "Name: " << names[i] << ", ID: " << ids[i] << ", Grade: " << grades[i] << endl;
    }
}

void updateGrade() {
    int id;
    cout << "Enter student ID to update grade: ";
    cin >> id;

    cin.ignore();
    
    bool found = false;
    for (int i = 0; i < currentSize; ++i) {
        if (ids[i] == id) {
            cout << "Current grade: " << grades[i] << endl;
            cout << "Enter new grade: ";
            cin >> grades[i];
            
            cin.ignore();
            
            cout << "Grade updated successfully." << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student ID not found." << endl;
    }
}

void searchStudent() {
    int id;
    cout << "Enter student ID to search: ";
    cin >> id;

    cin.ignore();
    
    bool found = false;
    for (int i = 0; i < currentSize; ++i) {
        if (ids[i] == id) {
            cout << "Name: " << names[i] << ", ID: " << ids[i] << ", Grade: " << grades[i] << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student ID not found." << endl;
    }
}