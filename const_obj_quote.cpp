/*
  * 如果不希望某个对象的值被改变，定义该对象的时候可以在前面加上const, 这是常量对象
  * 常量成员函数: 在类的成员函数说明后面加const，执行期间不应修改其所作用的对象
    所以它既不能用来修改成员变量的值，也不能调用非常量成员函数。
  * 两个成员函数，名字和参数列表都一样，但一个是const，另一个不是，这算重载。
  * 常引用经常用来作函数参数，这样可以避免调用复制构造函数，节省时间
    class Sample{
        ...
    };
    void PrintObj(const Sample & o)//避免调用复制构造函数
    {...}
*/
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

class Sample
{
public:
    int value;
public:
    int getValue() const;
    int getValue();//重载
    void func()
    {}
    Sample(int v)
        : value(v)
    {};
};
int Sample::getValue() const
{
    // value = 0;//wrong
    // func();//wrong
    return value;

}
int Sample::getValue()
{
    //重载
    return 2 * value;
}

int main()
{
    const Sample Obj1(1);//常量对象
    Sample Obj2(1);
    cout << Obj1.getValue()/*常量对象调用常量成员函数*/
         << "," << Obj2.getValue()/*非常量对象调用非常量成员函数*/
         << endl;
    return 0;
}