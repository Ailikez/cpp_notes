/*
    * 交换两个变量值的函数模板
    *
*/
#include <iostream>
using namespace std;
template<class T>
void Swap(T& x, T& y)
{
    T tmp = x;
    x = y;
    y = tmp;
}
/*
    * 函数模板中可以有不止一个类型参数
    *
*/
template<class T1, class T2>
T2 print(T1 arg1, T2 arg2)
{
    return arg2;
}
/*
    * 求数组最大元素的MaxElement函数模板
    *
*/
template<class T>
T MaxElement(T a[], int size)
{
    T tmpMax = a[0];
    for (int i = 1; i < size; ++i)
        if (tmpMax < a[i])
            tmpMax = a[i];
    return tmpMax;
}
/*
    * 函数模板还可以重载，只要形参表不一样即可
*/
template<class T>
void print(T arg1, T arg2)//之前是 T2 print(T1 arg1, T2 arg2)
{
    ;//do nothing
}
/*
    * c++编译器调用函数时遵循以下优先顺序
    *   1.先找 参数完全匹配的 普通函数（不是由模板实例化得到的函数）
    *   2.再找 参数完全匹配的 模板函数
    *   3.在找 实参 经过自动类型转换 后能够匹配的普通函数
    *   以上均未找到，编译器报错
*/
template<class T>
T Max(T a, T b)
{
    cout << "Template Max 1" << endl;
    return 0;
}
template<class T, class T2>
T Max(T a, T2 b)
{
    cout << "Template Max 2" << endl;
    return 0;
}
double Max(double a, double b)
{
    cout<<"MyMax"<<endl;
    return 0;
}
/* 赋值兼容原则引起函数模板中类型参数的二义性 */
/* myFunction(5, 8.4) 就会引起问题*/
/* 要避免这个问题可以在模板中使用多个类型参数 */
template<class T>
T myFunction(T arg1, T arg2)
{
    cout << arg1<< ""<<arg2<endl;
    return arg1;
}
int main()
{
    int n = 1, m = 2;
    Swap(n, m);//编译器自动生成void Swap(int&, int&)函数
    double f = 1.2, g = 3.4;
    Swap(f, g);//编译器自动生成void Swap(double&, double&)函数
    cout << "n: " << n << "m: " << m << endl;
    cout << "f: " << f << "g: " << g << endl;


    /* c++编译器模板函数优先顺序 */
    int i=4,j=5;
    Max(1.2, 3.4);//调用Max(double, double)函数
    Max(i,j);//调用第一个 T Max(T a, T b)模板生成的函数
    Max(1.2, 3);//调用第二个 T Max(T a, T2 b)模板生成的函数
    return 0;
}