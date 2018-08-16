// #define eg_static_cast
// #define eg_reinterpret_cast
// #define eg_const_cast
#define eg_dynamic_cast
#ifdef eg_static_cast
/*
 * 1.static_cast
 *      static_cast用来进行比较"自然"和低风险的转换，比如整型和实数型、字符之间的互相转换。
 *      static_cast不能用来在不同类型的指针之间相互转换，
 *          也不能用于整型和指针之间的相互转换，
 *          也不能用于不同类型的引用之间的相互转换
 *
 * */
#include <iostream>
using namespace std;
class A
{
public:
    operator int() {return 1;}//重载int类型转换运算符，不写返回值
    operator char*() {return NULL;}//重载char*类型转换运算符，不写返回值
};
int main(int argc, char* argv[])
{
    A a;
    int n;
    char* p = "static_cast";
    n = static_cast<int>(3.14);//n的值变为3
    n = static_cast<int>(a);//调用a.operator int(), n的值变为1
    p = static_cast<char*>(a);//调用a.operator char*(), p的值变为NULL
    // n = static_cast<int>(p);//编译错误，static_cast不能将指针转换成整型
    // p = static_cast<char*>(n);//编译错误，static_cast不能将整型转换成指针
    return 0;
}
#elif defined eg_reinterpret_cast
/*
 * reinterpret_cast用来进行各种不同类型的指针之间的转换、不同类型的引用之间的转换、以及指针和能容纳
 * 得下指针的整型之间转换。转换的时候，执行的是逐个比特拷贝的操作。
 * */
#include <iostream>
using namespace std;
class A
{
public:
    int i;
    int j;
    A(int i_)
        : i(i_), j(i_)
    {}
};
int main(int argc, char* argv[])
{
    A a(100);
    int& r = reinterpret_cast<int&>(a);//强行让r引用a
    r = 200;//把a.i变成了200
    cout<<a.i<<","<<a.j<<endl;//输出200，100
    int n = 300;
    A* pa = reinterpret_cast<A*> (&n);//强行让pa指向n
    pa->i = 400;// n变成400
    cout << hex << pa << endl;
    // pa->j = 500;// 可能会使程序崩溃
    cout << n <<endl;
    long long la = 0x12345678abcdLL;
    // pa = reinterpret_cast<A*>(la);//la太长，只取低32位5678abcd拷贝给pa
    // uint32_t u = reinterpret_cast<uint32_t>(pa);//pa逐比特拷贝到u
    // cout << hex << u << endl;
    typedef void (*PF1)(int);
    typedef int (*PF2)(int, char*);
    PF1 pf1;
    PF2 pf2;
    pf2 = reinterpret_cast<PF2>(pf1);//两个不同类型的函数指针之间可以互相转换
    return 0;
}
#elif defined eg_const_cast
/*
 * const_cast
 *  用来进行 去除const属性的转换。将const引用转换成同类型的非const引用，
 *  将const指针转换为非const类型的指针时使用。例如：
 *      const string s = "inception";
 *      string& p = const_cast<string&>(s);
 *      string* ps = const_cast<string*>(&s);//&s的类型是const string*
 * */
#elif defined eg_dynamic_cast
/*
 * dynamic_cast
 *      - dynamic_cast专门用于将多态基类的指针或引用，强制转换为派生类的指针或引用，
 *        而且能够检查转换的安全性(基类指针是不是真的指向派生类指针)。
 *        对于不安全的转换，转换结果返回NULL指针。
 *      - dynamic_cast不能用于将非多态基类的指针或引用，强制转换成派生类的指针或引用
 * */
#include <iostream>
#include <string>
using namespace std;
class Base
{
    //有虚函数，因此是多态基类
public:
    virtual ~Base(){}
};
class Derived : public Base {};
int main()
{
    Base b;
    Derived d;
    Derived *pd;
    pd = reinterpret_cast<Derived*> (&b);//不管安全不安全，一定能成功
    if(pd == NULL)//pd不会为NULL
        //reinterpret_cast不检查安全性，总是进行转换
        cout<<"unsafe reinterpret_cast"<<endl;
    pd = dynamic_cast<Derived*>(&b);
    if(pd == NULL)//pd是NULL，因为&b不指向派生类对象
        cout << " unsafe dynamic_cast1 " << endl;
    Base *pb = &d;
    pd = dynamic_cast<Derived*>(pb);//安全的转换，pb原本指向派生类对象
    if(pd == NULL)//不成立
        cout << " unsafe dynamic_cast2 " << endl;
    Derived& r = dynamic_cast<Derived&> (b);//引用不会有NULL，如何判断该转换是否安全呢？
    //答案就是下一节：异常处理
    return 0;
}
#endif