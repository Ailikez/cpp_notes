#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
/*
    * 解释cout << 5 << endl;为啥可以运行
    * cout是ostream类的对象，明显<<是经过重载的
    * 实际上是 cout.operator<<(5).operator<<(endl)
    * 也即是说运算符重载函数的返回值得是cout对象的引用
*/
//例子，重载<<使cout<<s<<"Hello";输出为5Hello
//明显，这里<<只能重载为普通全局函数
class CStudent
{
public:
    int nAge;
};
ostream& operator<<(ostream& o, const CStudent s)
{
    o << s.nAge;
    return o;
}
/*
* 例子
* 假定c是Complex复数类的对象，实现cout<<c;的输出为“a+bi”的形式
* cin>>c;可以以“a+bi”的形式从键盘输入，并使c.real=a,c.imag=b
*/
class Complex
{
    double real, imag;
public:
    Complex(double r, double i)
        : real(r), imag(i)
    {}
    friend ostream& operator<<(ostream& o, const Complex c);
    friend istream& operator>>(istream& i, Complex& c);
};
ostream& operator<<(ostream& o, const Complex c)
{
    cout << c.real << "+" << c.imag << "i";
    return o;
}
istream& operator>>(istream& i, Complex& c)
{
    string s;
    i>>s;//读入字符串
    int pos = s.find("+",0);
    string sTmp = s.substr(0, pos);
    c.real=atof(sTmp.c_str());
    sTmp = s.substr(pos+1, s.length()-pos-2);
    c.imag = atof(sTmp.c_str());
    return i;
}
int main()
{
    CStudent s1;
    s1.nAge = 5;
    cout << s1 << "Hello" << endl;

    Complex c(1, 1);
    int n;
    cin >> c >> n;
    cout << c << "," << n;
    return 0;
}