/*
    * 函数对象
    *   - 如果一个类重载了运算符"()"，则该类的对象就成为函数对象
*/
/*
    * differences between "typename" & "class"
    *   - typename and class are interchangeable in the basic case of specifying a template
    *       "template<class T>" and "template<typename T>" are equivalent.
    *   - there are specific cases where there is a difference between typename and class.
    *       1. 当需要表示某标识符是类型的时候用只能用typename而不能用class。(C++17之后可以互换)
    *           ------------------------------------------------------------
    *            template <class T>
    *            class MyClass{
    *                typename T::SubType * ptr;
    *                ...
    *            };
    *           在这里，typename指出SubType是class T中定义的一个类型，因此ptr是一个指向T::SubType类型的指针。
    *           如果没有关键字typename，SubType会被当成一个static成员，
    *           于是   T::SubType * ptr   会被解释为类型T内的数值SubType与ptr的乘积
    *
    *           注意，如果要把一个template中的某个标识符号指定为一种型别，就算是意图显而易见，
    *           关键字typename也是不能省略的，因此C++的一般规则是，除了使用typename修饰之外，
    *           template内的任何标识符号都被视为一个值而不是一个型别。
    *           -------------------------------------------------------------
    *       2. You also must use class when explicitly instantiating a template:
    *          ---------------------------
    *          template class Foo<int>;
    *          ---------------------------
*/
/*
    * STL中的 函数对象 类模板，头文件<functional>\
    *   - 首先==它们是模板，其次他们都实现了operator()成员函数，所以叫做哈桑农户对象类模板
    * greater函数对象类模板
    *   template <class T>
    *   struct greater:public binary_function<T, T, bool>{
    *       bool operator() (const T& x, const T& y) const{
    *           return x > y;
    *           //注意这里是用>号比较大小，与传统使用<比较大小结果返回相反哦
    *       }
    *   }
    * greater的应用
    *   + list 有两个sort成员函数
    *       - void sort();
    *           将list中元素按照"<"规定的比较方法升序排列。
    *       - template <class _Compare>
    *         void sort(_Compare op);
    *           将list中元素按照op规定的比较方法升序排列。即要比较x，y大小时，看op(x,y)的返回值，
    *           为true则认为x<y, 正好与greater相反
    * 在STL中使用自定义的‘大’‘小’关系
    *   关联容器和STL中的许多算法，都是可以使用函数或者函数对象自定义比较器的。在自定义了比较器op的情况下
    *   以下三种说法等价：
    *       1) x小于y
    *       2) op(x, y)返回值为true
    *       3) y大于x
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <list>
using namespace std;
//Dev C++中Accumulate源代码1:
template<typename _RequireInputIter, typename _Tp>
//typename 等价于class
_Tp _accumulate(_RequireInputIter __first, _RequireInputIter __last, _Tp __init)
{
    for (; __first != __last; ++__first)
        __init = __init + *__first;
    return __init;
};
//Dev C++中Accumulate源代码2:
template<typename _RequireInputIter, typename _Tp, typename _BinaryOperation>
_Tp _accumulate(_RequireInputIter __first, _RequireInputIter __last,
               _Tp __init, _BinaryOperation __binary_op)
{
    for (; __first != __last; ++__first)
        __init = __binary_op(__init, *__first);
    //调用该函数时，和__binary_op对应的实参可以是个 函数指针 或者 函数对象 或者 函数名字
    return __init;
};
class CMyAverage
{
public:
    double operator()(int a1, int a2, int a3)
    {
        return (double) (a1 + a2 + a3) / 3;
    }
};

CMyAverage average;//函数对象

int SumSquares(int total, int value)
{ return total + value * value; }
//函数模板PrintInterval
template<class T>
void PrintInterval(T first, T last)
{
    //输出区间[first，last)中的元素
    for (; first != last; ++first)
        cout << *first << " ";
    cout << endl;
}
//类模板SumPowers
template <typename T>
class SumPowers
{
private:
    int power;
public:
    SumPowers(int p)
        : power(p)
    {}
    const T operator()(const T &total, const T &value)
    {
        //计算value的power次方，累加到total
        T v = value;
        for (int i = 0; i < power - 1; ++i)
            v = v * value;
        return total + v;
    }
};
/*------------------------*/
/*      greater的应用      */
/*------------------------*/
class MyLess
{
public:
    bool operator() (const int& c1, const int& c2)
    { return (c1 % 10) < (c2 % 10);/*谁个位数小谁就小*/ }
};
template<class T>
void Print(T first, T last)
{
    for(; first!=last; ++first)
        cout << *first << ",";
}
/* 例题：写出MyMax模板 */
bool MyCompare(int a1, int a2)
{
    if ((a1%10) < (a2%10))
        return false;
    else
        return true;
}
template <typename _iter , typename _op>
_iter MyMax(_iter first, _iter last, _op op)
{
    _iter tmpMax = first;
    for (; first != last; ++first)
        if(op(*tmpMax, *first))
            tmpMax = first;
    return tmpMax;
};
int main(int argc, char *argv[])
{
    cout << average(3, 2, 3) << endl;//average.operator()(3,2,3)
    constexpr int SIZE = 10;
    int a1[] = {1,2,3,4,5,6,7,8,9,10};
    vector<int> v(a1, a1+SIZE);
    cout << "1) "; PrintInterval(v.begin(), v.end());/* 这里直接用的话要依靠实参推断 */
    int result = accumulate(v.begin(), v.end(), 0, SumSquares);
    cout << "2) squared sum: " << result << endl;
    result = accumulate(v.begin(), v.end(), 0, SumPowers<int>(3)/*函数对象*/);
    cout << "3) cubic sum: " << result << endl;
    /*------------------------*/
    /*      greater的应用      */
    /*------------------------*/
    const int _SIZE = 5;
    int a[_SIZE] = {5,21,14,2,3};
    list<int> lst(a, a+_SIZE);
    lst.sort(MyLess()/*调用构造函数返回临时函数对象*/);
    Print(lst.begin(), lst.end());
    cout << endl;
    lst.sort(greater<int>());//greater<int>()是个对象
    //greater是类模板，greater<int>是一个类，greater<int>()是一个临时类对象
    Print(lst.begin(), lst.end());
    cout << endl;
    /* 例题：写出MyMax模板 */
    int b[] = {35,7,13,19,12};
    cout << *MyMax(b,b+5,MyLess()) << endl;
    cout << *MyMax(b,b+5,MyCompare) << endl;
    return 0;
}
/*
    accumulate工作流程分析
    int result = accumulate(v.begin(), v.end(), 0, SumSquares);
    实例化出：
    int accumulate(vector<int>::iterator first,
                    vector<int>::iterator last,
                    int init,
                    int (*op)(int, int)//函数指针跟SumSquares这个函数名匹配
                  )
    {
        for(;first != last; ++first)
            init = op(init, *first);
        return init;
    }

    int result = accumulate(v.begin(), v.end(), 0, SumPowers<int>(3));
    实例化出：
    int accumulate(vector<int>::iterator first,
                    vector<int>::iterator last,
                    int init,
                    SumPowers<int> op //函数对象类型
                  )
    {
        for(;first != last; ++first)
            init = op(init, *first);//调用成员函数operator()
        return init;
    }
*/