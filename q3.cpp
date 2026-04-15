#include <iostream>

class ComplexNumber {
private:
    double real;
    double imag;
public:
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(real + other.real, imag + other.imag);
    }

    ComplexNumber operator-(const ComplexNumber& other) const {
        return ComplexNumber(real - other.real, imag - other.imag);
    }

    ComplexNumber operator*(const ComplexNumber& other) const {
        return ComplexNumber(real * other.real - imag * other.imag,
                             real * other.imag + imag * other.real);
    }

    bool operator==(const ComplexNumber& other) const {
        return (real == other.real) && (imag == other.imag);
    }

    void display() const {
        std::cout << real << (imag >= 0 ? "+" : "") << imag << "i" << std::endl;
    }
};

int main() {
    ComplexNumber c1(-3, 4);
    ComplexNumber c2(1, 2);
    ComplexNumber sum = c1 + c2;
    sum.display();

    ComplexNumber c3(8, 3);
    ComplexNumber c4(5, 6);
    ComplexNumber diff = c3 - c4;
    diff.display();

    ComplexNumber c5(-2, -3);
    ComplexNumber c6(1, 4);
    ComplexNumber prod = c5 * c6;
    prod.display();

    ComplexNumber c7(3, 5);
    ComplexNumber c8(3, 5);
    ComplexNumber c9(4, 5);
    
    std::cout << (c7 == c8) << std::endl;
    std::cout << (c7 == c9) << std::endl;

    return 0;
}
