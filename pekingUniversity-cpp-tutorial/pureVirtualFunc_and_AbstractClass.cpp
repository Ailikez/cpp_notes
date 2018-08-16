/*
    * 纯虚函数：没有函数体，像这样 virtual void Print() = 0;
    * 抽象类：
    *   - 包含纯虚函数的类
    *   - 只能作为基类来派生新类
    *   - 不能创建抽象类的对象
    *   - 抽象类的指针和引用 -> 由抽象类派生出来的类和对象
    *       A a；//错，A为抽象类，不能创建对象
    *       A* pa；//对，可以定义指针和引用
    *       pa = new A；//错，不能创建对象
    *   - 抽象类中
    *       - 成员函数中可以调用纯虚函数
    *       - 析构/构造函数不可以调用纯虚函数
    *   - 如果一个类从抽象类派生而来，他必须实现基类中所有纯虚函数才能变成非抽象类
*/
#include <iostream>
using namespace std;
class A
{
public:
    virtual void vf()=0;
    //void g(){this->vf();}
    void g()
    { vf(); }
    A()
    {}
};
class B: public A
{
public:
    void vf()
    {
        cout << "B::f()" << endl;
    }
};
int main(int argc, char *argv[])
{
    B b;
    b.g();
    return 0;
}