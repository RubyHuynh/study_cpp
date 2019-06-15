// Desc: Practice Operator overloading <<, +
#include <iostream>
#include <iterator>
#include <ostream>
// will not "using namespace xx" to learn namespace

class Complex {
private:
    int _real, _img;

public:
    Complex(int r = 10, int i= 20) {
        _real = r;
        _img = i;
    }
    ~Complex() {
        std::cout << "destructed" << std::endl;
    }

    int getVal() {
        return _real + _img;
    }

    int getReal() {
        return _real;
    }

    // "this" is the first variable implicitly
    Complex operator + (Complex const &obj) {
        Complex rs;
        rs._real = this->_real;
        rs._img = this->_img + obj._img;
        return rs;
    }
};

// must define as a free function because the first param is ostream.
std::ostream& operator << (std::ostream& ostr, Complex& obj) {
    ostr << "overloaded: " << obj.getVal() << std::endl;
    return ostr;
}

int main() {
    Complex c1(1,2), c2(3,4), c3, c4;
    std::cout << "c1 real=" << c1.getReal() << " sum= "<< c1.getVal() << std::endl;
    std::cout << "c2 real=" << c2.getReal() << " sum= "<< c2.getVal() << std::endl;
    std::cout << "=========Begin playing" << std::endl;
    c3 = c1 + c2;
    std::cout << c3;
    std::cout << "c3 real=" << c3.getReal() << " sum=" << c3.getVal() << std::endl;
    c4 = c2 + c1;
    std::cout << c4;
    std::cout << "c4 real=" << c4.getReal() << " sum=" << c4.getVal() << std::endl;
    std::cout << "=========End playing" << std::endl;
    return 0;
}