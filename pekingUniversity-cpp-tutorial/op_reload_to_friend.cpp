/*
    * 通常将op重载为成员函数或普通函数
    * 何时应该重载为友元函数？
    * 1.普通成员函数，不能满足使用要求
    * 2.普通函数，又不能访问类的私有成员
*/
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
class Complex
{
private:
    double real, imag;
public:
    Complex(double r, double i)
        : real(r), imag(i)
    {};
    Complex operator+(double r);//普通成员函数可以解释c+5这样的表达式 --> c.operator+(5)
    //要使得5+c能被解释，只能定义成普通函数，但是普通函数不能访问私有成员啊，所以只能变友元函数
    friend Complex operator+(double r, const Complex & c);
};
Complex Complex::operator+(double r)//不能解释5+c
{
    return Complex(real + r, imag);
}
Complex operator+(double r, const Complex &c)
{
    return Complex(c.real + r, c.imag);
}
