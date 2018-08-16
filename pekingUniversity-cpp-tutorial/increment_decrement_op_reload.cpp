/*
    * 有前置后置之分，i++， ++i
    * 前置运算符重载为一元函数:
    *   1.重载为成员函数
    *       T operator++();
    *       T operator--();
    *   2.重载为全局函数
    *       T operator++(T);
    *       T operator--(T);
    *   3.++obj, obj.operator++(), operator++(obj)都调用以上函数
    * 后置运算符要重载为为二元运算符，多写一个参数，没具体意义，只是用来区分前置运算符重载
    *   1.重载为成员函数
    *       T operator++(int);
    *       T operator--(int);
    *   2.重载为全局函数
    *       T operator++(T, int);
    *       T operator--(T, int);
    *   3.obj++, obj.operator++(0), operator++(obj,0)都调用以上函数，编译器一般将其初始化为零值
*/
/*
    * c++不允许定义新的运算符
    * 重载后运算符的含义应该符合日常习惯，符合数学上的规则
    * 重载运算符不能改变其优先级
    * 不能被重载的运算符：.   .*  ::  ?:  sizeof
    * 重载时必须声明为类的成员函数的运算符：() []  ->  =
    *
*/
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
class CDemo
{
    int n;
public:
    explicit CDemo(int i = 0)
        : n(i)
    {}
    CDemo operator++();//前置
    CDemo operator++(int);//后置
    explicit operator int()
    {
        //强制类型转换重载不能写返回值类型
        //实际上其返回值类型是类型强制转换运算符所代表的类型
        return n;
    }
    friend CDemo operator--(CDemo&);//前置全局重载函数
    friend CDemo operator--(CDemo&, int);//后置全局重载函数

};
CDemo CDemo::operator++()
{
    //实现++i
    n++;
    return *this;
}
CDemo CDemo::operator++(int)
{
    //实现i++的功能
    CDemo tmp(*this);//这既是为啥++i，比i++效率高
    n++;//实现自增
    return tmp;//返回的还是i
}
CDemo operator--(CDemo& d)
{
    d.n--;
    return *this;
}
CDemo operator--(CDemo& d, int)
{
    CDemo tmp(d);
    d.n--;
    return tmp;
}
