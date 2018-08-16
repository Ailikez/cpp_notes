/*
    * 派生类对象包含基类对象，在执行派生类构造函数之前先执行基类的构造函数, 初始化派生类对象从基类继承的成员
    * 调用基类构造函数的两种方式：
    *   -显式方式：
    *       派生类构造函数中-》基类的构造函数提供参数
    *       derived::derived(arg_derived_list) : base(arg_base_list)
    *   -隐式方式：
    *       派生类的构造函数中，省略基类构造函数时
    *       派生类的构造函数自动调用基类的默认构造函数
    * 消亡时析构函数调用顺序相反
    * 派生类包含其他类的对象时，初始化顺序是 基类->成员对象类->派生类
*/
#include <iostream>
using namespace std;
class Skill
{
    int n;
public:
    Skill(int n_)
        : n(n_)
    { cout << "Skill" << n << "Constructor called" << endl; }
    ~Skill()
    { cout << "Skill" << n << "Destructor called" << endl; }
};
class Bug
{
private:
    int nLegs, nColor;
public:
    int nType;
    void PrintBug()
    {}
    Bug(int legs, int color)
        : nLegs(legs), nColor(color), nType(1)
    {
        cout << "Bug Constructor called" << endl;
    }
    ~Bug()
    { cout << "Bug Destructor called" << endl; }
};
class FlyBug: public Bug
{
private:
    int nWings;
    Skill sk1, sk2;
public:
    FlyBug(int legs, int color, int wings)
        : Bug(legs, color), sk1(5), sk2(color), nWings(wings)
    { cout << "FlyBug Constructor called" << endl; }
    /* 错误的FlyBug构造函数 */
    //FlyBug(int legs, int color, int wings)
    //{
    //  nLegs = legs;//错误，不能访问私有成员
    //}
    ~FlyBug()
    { cout << "FlyBug Destructor called" << endl; }
protected:

};
int main(int argc, char *argv[])
{
    FlyBug fb(2, 3, 4);
    fb.PrintBug();
    fb.nType = 1;
    //fb.nLegs=2;//wrong,private
    return 0;
}