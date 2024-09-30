#include <iostream>
using namespace std;

// Base class A
class A {
public:
    void Add(int a, int b) {
        cout << "Class A: " << a + b << endl;
    }
};

// Derived class B inheriting from A
class B : public A {
    // Inherits Add(int, int) from A
};

// Derived class C inheriting from B
class C : public B {
public:
    void Add(int a, float b) {
        cout << "Class C: " << a + b << endl;
    }
};

// Derived class D inheriting from A
class D : public A {
    // Inherits Add(int, int) from A
};

// Derived class E inheriting from D
class E : public D {
public:
    void Add(float a, int* b) {
        cout << "Class E: " << a + *b << endl;
    }
};

// Derived class F inheriting from C and E
class F : public C, public E {
public:
    void Add(float a, float b) {
        cout << "Class F: " << a + b << endl;
    }
};

int main() {
    A a;
    B b;
    C c;
    D d;
    E e;
    F f;

    // Method calls
    a.Add(3, 3);       // Calls A::Add(int, int)
    c.Add(3, 3.5f);    // Calls C::Add(int, float)
    f.Add(3.5f, 5.0f); // Calls F::Add(float, float)

    return 0;
}
