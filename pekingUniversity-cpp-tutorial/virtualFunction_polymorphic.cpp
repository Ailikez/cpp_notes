/*
    * 虚函数：在类的定义中，前面有virtual关键字的成员函数
    *   class base { virtual int get();};
    *   int base::get(){}
    * virtual关键字只用在类定义里的函数声明中，谐函数体的时候不写
    * 构造函数和静态成员函数不能是虚函数
*/
/*
    * 多态的表现形式1
    *   - 派生类的指针可以赋给基类指针
    *   - 通过基类指针调用基类和派生类中的同名虚函数时：
    *       1.若该指针指向一个基类对象，那么被调用的是基类的虚函数
    *       2.如该指针指向一个派生类的对象，那么被调用的是派生类的虚函数
    *   这种机制就叫做 多态
    * 多态的表现形式2
    *   - 派生类的对象可以赋给基类的引用
    *   - 通过基类引用调用基类和派生类中的同名虚函数时：
    *       1.若该引用引用的是一个基类对象，那么被调用的是基类的虚函数
    *       2.如该引用引用的是一个派生类的对象，那么被调用的是派生类的虚函数
    *   这种机制也叫做 多态
*/
#include <iostream>
using namespace std;
class CBase
{
private:
public:
    virtual void SomeVirtualFunction()
    { cout << "CBase VirtualFunction called" << endl; }
protected:
};
class CDerived: public CBase
{
private:
public:
    virtual void SomeVirtualFunction()
    { cout << "CDerived VirtualFunction called" << endl; }
protected:
};

int main(int argc, char *argv[])
{
    CDerived ODerived;
    CBase *p = &ODerived;//p指向派生类对象
    p->SomeVirtualFunction();////实际调用哪个虚函数取决于p指向哪种类型的对象

    CBase& r = ODerived;//r是派生类对象的引用
    r.SomeVirtualFunction();////实际调用哪个虚函数取决于r是哪种类型的对象的引用
    return 0;
}