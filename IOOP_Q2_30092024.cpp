//file reading in cpp
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Base class A
class A {
public:
    void displayInfo() {
        cout << "This is class A." << endl;
    }

    void writeToFile1(const string& data) {
        ofstream file("file1.txt", ios::app);
        if (file.is_open()) {
            file << data << endl;
            file.close();
        } else {
            cerr << "Unable to open file1.txt" << endl;
        }
    }
};

// Class B inherits from A
class B : public A {
public:
    void displayInfo() {
        cout << "This is class B." << endl;
    }

    void writeDataToFile1(const string& data) {
        writeToFile1(data); // Call method from A
    }
};

// Class C inherits from A
class C : public A {
public:
    void displayInfo() {
        cout << "This is class C." << endl;
    }

    void writeToFile2(const string& data) {
        ofstream file("file2.txt", ios::app);
        if (file.is_open()) {
            file << data << endl;
            file.close();
        } else {
            cerr << "Unable to open file2.txt" << endl;
        }
    }
};

// Class D inherits from both B and C
class D : public B, public C {
public:
    void displayInfo() {
        cout << "This is class D." << endl;
    }

    void writeToBothFiles(const string& data) {
        writeDataToFile1(data); // Call method from B
        C::writeToFile2(data);  // Call method from C
    }
};

int main() {
    D obj;
    obj.displayInfo();

    string data = "Hello, this is sample data.";
    obj.writeToBothFiles(data); // Write to both files

    return 0;
}
