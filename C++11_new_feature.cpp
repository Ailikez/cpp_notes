/*
 * c++11 新特性
 * */
// #define eg_uniform_initialization
// #define eg_default_value_of_class_member_variables
// #define eg_keyword_auto
// #define eg_keyword_decltype
// #define eg_smart_pointer
// #define eg_empty_pointer
// #define eg_range_for_loop
#define eg_unorderd_map
// #define eg_rightvalue_quotation_and_move_semantics
#ifdef eg_uniform_initialization
/*
 * 统一化初始化方法
 * */
#include <vector>
#include <map>

using namespace std;

int arr[3]{1, 2, 3};

vector<int> iv{1, 2, 3};

map<int, string> mp{{1, "a"}, {2, "b"}};

string str{"Hello World"};

int *p = new int[20]{1, 2, 3};

struct A
{
    int i, j;
    A(int i_, int j_)
        : i(i_), j(j_)
    {}
};
A func(int m, int n)
{ return {m, n}; }/* 不推荐 */
int main(int argc, char* argv[])
{
    A *pa = new A{3, 7};
    // A a(1,2);//使用ctor
    return 0;
}
#endif

#ifdef eg_default_value_of_class_member_variables
// 成员变量默认初始值
#include <iostream>
using namespace std;

class B
{
public:
    int m = 1234;// 默认初始值, 从java偷学的？
    int n;
};
int main(int argc, char *argv[])
{
    B b;
    cout << b.m << endl;
    return 0;
}
#endif
#ifdef eg_keyword_auto
// 用auto定义变量，编译器可以自动判断变量的类型
#include <iostream>
#include <map>
using namespace std;
class A
{
    A operator+(int n, const A &a)
    {
        return a;
    }
};
template<class T1, class T2>
auto add(T1 x, T2 y) /* 后面的用来指明函数返回值类型 */-> decltype(x + y)
{ return x + y; }
auto d = add(100, 1.5);// d是duble类型
auto e = add(100, A());// e是A类型
auto i = 100;// i是int类型
auto p = new A();// p是A*类型
auto k = 34343LL;// k是long long类型
map<string, int, greater<string> > mp;

int main(int argc, char *argv[])
{
    for (auto i = mp.begin(); i != mp.end(); ++i)
        cout << i->first << "," << i->second;
    // i的类型是 map<string, int, greater<string> >::iterator
    return 0;
}
#endif

#ifdef eg_keyword_decltype
// 求表达式的类型
int i;
double t;
struct A {double x;};
const A *a = new A();
decltype(a) x1;// x1 is A* type
decltype(i) x2;// x2 is int type
decltype(a->x) x3;// x3 is double type
decltype((a->x)) x4 = t;// x4 is double& type???

#endif
#ifdef eg_smart_pointer
/*
 * 头文件<memory>
 * 通过shared_ptr的构造函数，可以让shared_ptr对象托管一个new运算符返回的指针写法如下：
 *      shared_ptr<T> ptr(new T);// T可以是int、char、类名等各种类型
 *      此后ptr就可以向T*指针一样来使用，即*ptr就是用new动态分配的那个对象，而且不用操心如何释放内存
 * 多个shared_ptr对象可以同时托管一个指针，系统会维护一个托管计数。当无shared_ptr托管该指针时，delete
 * shared_ptr对象不能托管指向动态分配的数组的指针，否则程序运行会出错
 * */
#include <memory>
#include <iostream>

using namespace std;
#if 0
    struct A
    {
        int n;
        A(int v = 0)
            : n(v)
        {}
        ~A()
        { cout << ">>>" << n << "destructor" << "<<<" << endl; }
    };
    int main(int argc, char *argv[])
    {
        shared_ptr<A> sp1(new A(2));// sp1托管A(2)
        shared_ptr<A> sp2(sp1);// sp2也托管A(2)
        cout << "1)" << sp1->n << "," << sp2->n << endl;
        shared_ptr<A> sp3;
        A* p = sp1.get();// p指向A(2)
        cout << "2)" << p->n << endl;
        sp3 = sp1;//现在sp1,sp2,sp3都托管A(2)
        cout << "3)" << (*sp3).n << endl;
        sp1.reset();//sp1放弃托管A(2)
        if(!sp1)
            cout << "4)sp1 is null" << endl;
        A* q = new A(3);
        sp1.reset(q);//sp1托管q
        cout<< "5)" << sp1->n << endl;//输出3
        shared_ptr<A> sp4(sp1);//sp4托管A(3)
        shared_ptr<A> sp5;
        // sp5.reset(q);// 不妥, 会使程序出错(*)
        sp1.reset();//sp1放弃托管A(3)
        cout << "before end main" << endl;
        sp4.reset();//sp4放弃托管A(3)
        cout << "end main" << endl;
        return 0;
    }
#else
    struct A {
        ~A() {cout << "~A" << endl;}
    };
    int main(int argc, char* argv[])
    {
        A* p = new A();
        shared_ptr<A> ptr(p);
        shared_ptr<A> ptr2;
        ptr2.reset(p);// 并不会增加ptr中对p的托管计数
        cout << "end" << endl;
        /*
         * 输出：
         *      end
         *      ~A
         *      ~A
         * 之后程序崩溃，因为p被删除了两次
         * */
        return 0;
    }
#endif
#endif
#ifdef eg_empty_pointer
#include <memory>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    int *p1 = NULL;
    int *p2 = nullptr;
    shared_ptr<double> p3 = nullptr;
    if (p1 == p2)
        cout << "equal 1" << endl;
    if (p3 == nullptr)
        cout << "equal 2" << endl;

    // if (p3 == p2);
    //error no match for 'operator=='
    // (operand types are 'std::shared_ptr<double>' and 'int*')

    if (p3 == NULL)
        cout << "equal 4" << endl;

    // bool b = nullptr;// b=false
    //converting to 'bool' from 'std::nullptr_t' requires
    // direct-initialization [-fpermissive]

    // int i = nullptr;// error, nullptr不能自动转换为整型
    // cannot convert 'std::nullptr_t' to 'int' in initialization

    return 0;
}
#endif
#ifdef eg_range_for_loop
#include <iostream>
#include <vector>
using namespace std;
struct A
{
    int n;
    A(int i)
        : n(i)
    {}
};
int main()
{
    int arr[]{1, 2, 3, 4, 5};
    for (int &e : arr)//&是引用
        e *= 10;
    for (int e : arr)
        cout << e << ",";
    cout << endl;
    vector<A> st(arr, arr + sizeof(arr) / sizeof(int));
    for (auto &it : st)
        it.n *= 10;
    for (A it: st)
        cout << it.n << ",";
    return 0;
}
#endif
#ifdef eg_rightvalue_quotation_and_move_semantics
// 右值：一般来说不能取地址的表达式，就是右值，能取地址的是左值
// class A{};
// A & r = A();//error, A()是无名变量，是右值
// A && r = A();//ok, r是右值引用
// 主要目的是提高程序运行的效率，减少需要进行深拷贝的对象进行深拷贝的次数
// 参考：https://www.cnblogs.com/felove2013/articles/3659013.html

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class String
{
public:
    char *str;
    String()
        : str(new char[1])
    { str[0] = 0; }
    String(const char *s)
    {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
    String(const String &s)
    {
        cout << ">>>copy constructor called<<<" << endl;
        str = new char[strlen(s.str) + 1];
        strcpy(str, s.str);//深拷贝
    }
    String &operator=(const String &s)
    {
        cout << ">>>copy operator=() called<<<" << endl;
        if (str != s.str) {
            delete[] str;
            str = new char[strlen(s.str) + 1];
            strcpy(str, s.str);
        }
        return *this;
    }
    /// @brief move constructor
    String(String &&s)
        : str(s.str)//让str指向s.str对应的空间
    {
        cout << "move constructor called" << endl;
        s.str = new char[1];
        s.str[0] = 0;
    }
    String &operator=(String &&s)
    {
        cout << ">>>move operator=() called<<<" << endl;
        if (str != s.str) {
            delete[] str;
            str = s.str;
            s.str = new char[1];
            s.str[0] = 0;
        }
        return *this;
    }
    ~String()
    { delete[] str; }
};
template<class T>
void MoveSwap(T &a, T &b)
{
    //不会出现深拷贝
    T tmp(move(a));// std::move(a)为右值，这里会调用move constructor
    //会修改a的内容，a是临时变量或可以被修改才不会出问题
    a = move(b);// move(b)为右值，这里会调用move assignment
    b = move(tmp);// move(tmp)为右值，因此这里会调用move assignment
}
int main()
{
    // String & r = String("this");// error
    String s;
    s = String("ok");//String("ok")是右值
    cout << "******" << endl;
    String &&r = String("this");
    cout << r.str << endl;
    String s1 = "hello", s2 = "world";
    String as = String("1");
    MoveSwap(s1, s2);//避免深拷贝
    cout << s1.str << endl;
    cout << s2.str << endl;

    return 0;
}
#endif
#ifdef eg_unorderd_map

#endif