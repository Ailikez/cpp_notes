/*
    * 问题的提出->定义一批相似的类->定义模板类->生成不同类
    * 以数组类为例：除了元素类类型不同，其余全部相同
    * 类模板
    *   - 在定义类的时候给它一个/多个参数
    *   - 这个/些参数表示不同的数据类型
    * C++的类模板写法:
    *   template<类型参数表>
    *   class 类模板名
    *   {
    *       成员函数和成员变量
    *   };
    * 类型参数表的写法：class 类型参数1，class 类型参数2，...
    
    * 用类模板定义对象写法如下：类模板名<真实类型参数表> 对象名(构造函数实际参数表);
    * 如果类模板有无参构造函数，那么也可以只写：类模板名<真实类型参数表> 对象名;
    
    * 编译器有类模板生成类的 过程 叫做 类模板的实例化
    *   - 编译器自动用具体的数据类型 替换 模板中的数据类型，生成模板类的代码
    
    * 由类模板实例化得到的类叫做 模板类
    *   - 类型参数指定的数据类型不同，得到的模板类不同
    
    * 同一个类模板的两个模板类是不兼容的
    *   Pair<string, int>* p;
    *   Pair<string, double> a;
    *   p = &a;//这就是错的，两个模板类不兼容
    
    * 类模板的参数声明中可以包括非类型参数
    *   template <class T, int elementsNumber>
    *   - 非类型参数：用来说明类模板中的 属性
    *   - 类型参数：用来说明类模板中的 属性类型， 成员操作的参数类型 和 返回值类型
*/

/* pair类 模板 */
#include <iostream>

using namespace std;

template<class T1, class T2>
class Pair
{
public:
    T1 key;//关键字
    T2 value;//值
    Pair(T1 k, T2 v)
        : key(k), value(v)
    {};//初始化构造函数
    bool operator<(const Pair<T1, T2> &p) const;//只比较大小，不修改任何值，定义成const
};

template<class T1, class T2>
bool Pair<T1, T2>::operator<(const Pair<T1, T2> &p) const
{
    return key < p.key;
}

/*
    * 函数模板作为类模板成员
*/
template<class T>
class A
{
public:
    template<class T2>
    //注意这里如改成<class T>...Func(T t)就会报错
    void Func(T2 t)
    { cout << t << endl; }//成员函数模板
};

/* 类模板的参数声明中可以包括非类型参数 */
template<class T, int size/*非类型参数size*/>
class CArray
{
    T array[size];//size是固定属性，使用了非类型参数来标记
public:
    void Print()
    {
        for (int i = 0; i < size; ++i)
            cout << array[i] << endl;
    }
};
/*
 * 类模板与继承
 * 类模板派生出类模板
 * 模板类(即类模板中类型/非类型参数实例化之后的类)派生出类模板
 * 普通类派生出类模板
 * 模板类派生出普通类
 */
/*(1)类模板从类模板派生*/
template<class T1, class T2>
class A1
{
    T1 v1;
    T2 v2;
};

template<class T1, class T2>
class B1: public A1<T2, T1>
{
    T1 v3;
    T2 v4;
};

template<class T>
class C1: public B1<T, T>
{
    T v5;
};

/*(2)类模板从模板类派生*/
template<class T1, class T2>
class A2
{
    T1 v1;
    T2 v2;
};

template<class T>
class B2: public A2<int, double>
{
    T v;
};//可以看到类模板A2<T1, T2>实例化为模板类A2<int, double>
/*(3)类模板从普通类派生*/
class A3
{
    int v1;
};

template<class T>
class B3: public A3
{
    T v;
};

/*(4)普通类从模板类派生*/
template<class T>
class A4
{
    T v1;
    int n;
};

class B4: public A4<int>//实例化模板类A4
{
    double v;
};

int main()
{
    /* 实例化一个Pair<string, int>类 */
    Pair<string, int> student("Tom", 19);
    cout << student.key << " " << student.value << endl;
    /* 成员函数模板例子 */
    A<int> a;
    a.Func('K');//成员函数模板Func被实例化, Func(char t)
    /* 类模板的参数声明中可以包括非类型参数 */
    CArray<double, 40> a2;
    CArray<int, 50> a3;
    /* 注意CArray<int, 40>和CArrray<int, 50>完全是两个类，这两个类之间不能互相赋值 */

    /*(1)类模板从类模板派生*/
    B1<int, double> obj11;//实际上变成class B<int, double>:public B<double, int>
    C1<int> obj12;
    /*(2)类模板从模板类派生*/
    B2<char> obj21;//自动生成两个模板类：A<int, double>和B<char>
    /*(3)类模板从普通类派生*/
    B3<char> obj31;
    /*(4)普通类从模板类派生*/
    B4 obj41;
    return 0;
}