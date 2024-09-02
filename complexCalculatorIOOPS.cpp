#include <iostream>
#include <cmath>
#include <boost/math/special_functions/gamma.hpp>
#include <complex>

using namespace std;
using namespace boost::math;

class complex {
    int real;
    int img;

public:
    complex(int r_no = 0, int img_no = 0) : real(r_no), img(img_no) {}

    void display() const {
        cout << "number: " << real << "+ i" << img << "\n";
    }

    friend complex operator+(const complex &, const complex &);
    friend complex operator-(const complex &, const complex &);
    friend complex operator*(const complex &, const complex &);
    friend complex operator/(const complex &, const complex &);

    complex power(int n) const {
        complex result(1, 0);
        complex base(real, img);
        
        for (int i = 0; i < n; ++i) {
            result = result * base;
        }

        return result;
    }

    // Add a constructor to create complex from complex<double>
    complex(const complex<double>& c) : real(static_cast<int>(c.real())), img(static_cast<int>(c.imag())) {}
};

// Arithmetic operators for complex class
complex operator+(const complex &c1, const complex &c2) {
    complex res;
    res.real = c1.real + c2.real;
    res.img = c1.img + c2.img;
    return res;
}

complex operator-(const complex &c1, const complex &c2) {
    complex res;
    res.real = c1.real - c2.real;
    res.img = c1.img - c2.img;
    return res;
}

complex operator*(const complex &c1, const complex &c2) {
    complex res;
    res.real = c1.real * c2.real - c1.img * c2.img;
    res.img  = c1.real * c2.img + c1.img * c2.real;
    return res;
}

complex operator/(const complex &c1, const complex &c2) {
    complex res;
    double denominator = pow(c2.real, 2) + pow(c2.img, 2);
    res.real = (c1.real * c2.real + c1.img * c2.img) / denominator;
    res.img  = (c1.img * c2.real - c1.real * c2.img) / denominator;
    return res;
}

// Generalized binomial coefficient function
complex<double> binomial_coefficient(const complex<double>& n, const complex<double>& r) {
    // Compute Gamma functions
    complex<double> gamma_n1 = gamma(n + 1);
    complex<double> gamma_r1 = gamma(r + 1);
    complex<double> gamma_nr1 = gamma(n - r + 1);

    // Compute binomial coefficient
    return gamma_n1 / (gamma_r1 * gamma_nr1);
}

int main() {
    cout << "hello\n";
    complex n1(1, 2);
    complex n2(1, 3);

    complex n3;
    char choice;
    cout << "Enter choice (+, -, *, /, ^, C): ";
    cin >> choice;

    if (choice == '^') {
        int power;
        cout << "Enter the power: ";
        cin >> power;
        n3 = n1.power(power);
    } else if (choice == 'C') {
        complex<double> n_real(n1.real, n1.img);
        complex<double> r_real(n2.real, n2.img);
        complex<double> result = binomial_coefficient(n_real, r_real);
        cout << "Binomial coefficient C(" << n_real << ", " << r_real << ") = " << result << endl;
        return 0; // Exit after computing binomial coefficient
    } else {
        n3 = calculate(n1, n2, choice);
    }

    n3.display();

    // Array of complex numbers
    complex arr[10];
    int r, img;
    for (int i = 0; i < 10; i++) {
        cout << i + 1 << ". Enter real part: ";
        cin >> r;
        cout << i + 1 << ". Enter imaginary part: ";
        cin >> img;
        arr[i] = complex(r, img);
    }

    // Sum of complex numbers
    complex sum(0, 0);
    for (int i = 0; i < 10; i++) {
        sum = sum + arr[i];
    }
    cout << "Sum of complex numbers: ";
    sum.display();

    return 0;
}
