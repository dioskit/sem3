#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Open the file in append mode
    ofstream file("student_info.txt", ios::app);

    // Variables to hold student information
    int no_students = 6;
    string student_names[no_students] = {"snow", "rob", "arya", "sansa", "brandon", "rickon"};
    int marks[no_students] = {14, 14, 9, 11, 7, 3};

    // Check if the file is open
    if (file.is_open()) {
        for (int i = 0; i < no_students; i++) {
            // Write the information to the file
            file <<"Name: "<< student_names[i] << "," << marks[i] << endl;
            cout << student_names[i] << " has been written to student_info.txt." << endl;
        }
        file.close(); // Close the file
    } else {
        cerr << "Unable to open file." << endl;
    }

    return 0;
}
