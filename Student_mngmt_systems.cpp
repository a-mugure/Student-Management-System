#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    int age;
    int marks[3];
    float average;
};

void addStudent(Student students[], int &n) {
    cout << "Enter student name: ";
    getline(cin, students[n].name);
    cout << "Enter student age: ";
    cin >> students[n].age;
    cout << "Enter marks in 3 subjects: ";
    for (int i = 0; i < 3; i++) {
        cin >> students[n].marks[i];
    }
    n++;
}

void displayStudents(Student students[], int n) {
    cout << "\nStudent Information:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nName: " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;
        cout << "Marks: ";
        for (int j = 0; j < 3; j++) {
            cout << students[i].marks[j] << " ";
        }
        cout << endl;
        cout << "Average: " << students[i].average << endl;
    }
}

void calculateAverages(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        int total = 0;
        for (int j = 0; j < 3; j++) {
            total += students[i].marks[j];
        }
        students[i].average = (float)total / 3;
    }
}

void sortStudents(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].average < students[j + 1].average) {
                swap(students[j], students[j + 1]);
            }
        }
    }
}

void findHighestLowest(Student students[], int n) {
    int highestIndex = 0, lowestIndex = 0;
    for (int i = 1; i < n; i++) {
        if (students[i].average > students[highestIndex].average) {
            highestIndex = i;
        }
        if (students[i].average < students[lowestIndex].average) {
            lowestIndex = i;
        }
    }
    cout << "\nHighest Average: " << students[highestIndex].name << " - " << students[highestIndex].average << endl;
    cout << "Lowest Average: " << students[lowestIndex].name << " - " << students[lowestIndex].average << endl;
}

void calculateClassAverage(Student students[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += students[i].average;
    }
    float classAverage = total / n;
    cout << "\nClass Average: " << classAverage << endl;
}

int main() {
    Student students[100];
    int n = 0;

    int choice;
    do {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Calculate Averages\n";
        cout << "4. Sort Students\n";
        cout << "5. Find Highest and Lowest\n";
        cout << "6. Calculate Class Average\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students, n);
                break;
            case 2:
                displayStudents(students, n);
                break;
            case 3:
                calculateAverages(students, n);
                break;
            case 4:
                sortStudents(students, n);
                break;
            case 5:
                findHighestLowest(students, n);
                break;
            case 6:
                calculateClassAverage(students, n);
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
