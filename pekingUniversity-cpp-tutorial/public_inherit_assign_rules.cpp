/*
    * class base{};
    * class derived: public base{};
    * base b; derived d;
    * 1.派生类对象可以赋值给基类对象: b=d;因为一个派生类对象是一个基类对象，反过来不行
    * 2.派生类对象可以用来初始化基类引用：base& br = d;
    * 3.派生类对象的地址可以赋值给基类指针：base* pb = &d;
    * 注意，如果派生方式是private或protected，则以上三条不可行
*/
/*
    * 直接基类和间接基类
    * 类A派生B，类B派生C，类C派生D，...
    *   - 类A是类B的直接基类
    *   - 类B是类C的直接基类，类A是类C的间接基类
    *   - 类C是类D的直接基类，类A、B是类D的间接基类
    * 在声明派生类时只需要列出他的直接基类
    *   - 派生类沿着类的层次自动向上继承他的间接基类
    *   - 派生类的成员包括
    *       - 派生类自己定义的成员
    *       - 直接基类中的所有成员
    *       - 所有间接基类的全部成员
*/
#include <iostream>
using namespace std;
class Base
{
private:

public:
    int n;
    explicit Base(int i)
        : n(i)
    { cout << "Base " << n << " Constructed" << endl; }
    ~Base()
    { cout << "Base " << n << " Destructed" << endl; }
protected:

};
class Derived: public Base
{
private:

public:
    Derived(int i)
        : Base(i)
    { cout << "Derived" << "Constructed" << endl; }
    ~Derived()
    { cout << "Derived" << "Destructed" << endl; }
protected:

};
class MoreDerived: public Derived
{
private:

public:
    MoreDerived()
        : Derived(4)
    { cout << "MoreDerived" << "Constructed" << endl;}
    ~MoreDerived()
    { cout << "MoreDerived" << "Destructed" << endl;}
protected:

};
int main(int argc, char *argv[])
{
    /* 构造函数从顶层开始执行 */
    MoreDerived Obj;
    return 0;
}