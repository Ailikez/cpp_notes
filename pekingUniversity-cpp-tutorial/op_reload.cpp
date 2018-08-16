/*
    * 运算符载实际上是函数重载
    * 返回值类型 operator 运算符 (形参表)
    * {...}
    * 程序编译时 把含运算符的表达式 转换成 对 运算符函数 的调用
    * 把运算符连接的操作数 转换成 运算符函数的 参数
    * 运算符被多次重载时，根据 实参的类型 决定调用哪个运算符函数
    * 运算符可以被重载为 普通函数，也可以重载为 类的成员函数
    * 重载为普通函数时，参数个数是运算符目数
    * 重载为成员函数时，参数个数时运算符目数减1
*/
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
class Complex
{
public:
    explicit Complex(double r = 0.0, double i = 0.0)
    {
        real = r;
        imag = i;
    }
    double real;
    double imag;
    //重载运算符为成员函数
    Complex operator-(const Complex &tmp) // a+b,看成是 a.operator-(b), 所以只有一个参数
    {
        return Complex(real - tmp.real, imag - tmp.imag);
    }
};
Complex operator+(const Complex &a, const Complex &b)//重载运算符为普通函数
{
    return Complex(a.real + b.real, a.imag + b.imag);
}
int main()
{
    Complex a(1, 2), b(3, 4), c, d;
    d = b - a;//d=b.operator-(a);
    c = a + b;//重载运算符, 相当于operator+(a, b)

    return 0;
}