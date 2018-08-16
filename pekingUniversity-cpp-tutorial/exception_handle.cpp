/* 异常处理
 *  - 程序运行中难免发生错误
 *      - 数组元素下标越界、访问NULL指针
 *      - 除数为零
 *      - 动态内存分配new需要的存储空间太大
 *      - 等等...
 *  - 引起这些异常的原因：
 *      - 代码质量不高，有bug
 *      - 输入数据不符合要求
 *      - 算法设计没有考虑周全
 *      - 等等...
 *  - 我们总希望在发生异常情况时
 *      - 不只是简单的终止程序运行
 *      - 能够反馈异常情况的信息：那一段代码发生的、什么类型的异常
 *      - 能够对程序运行中已发生事情做些处理：取消对输入文件的改动啊、释放已经申请的系统资源等
 *  - 通常的做法是：在预计会发生异常的地方，加入相应的代码，但这种做法并不总是合适的。
 *      .....//对文件A进行了相关操作
 *      fun(arg,...);//可能会发生异常
 *      ....
 *      - caller该如何知道fun(arg, ...)是否发生异常
 *          - 如果没发生，可以继续执行
 *          - 发生了异常，因该在结束程序运行前还原对文件A的操作
 *      - fun(arg,...)是别人已经编写好的代码
 *          - fun(arg, ...)的编写者不知道其他人会怎样使用这个函数
 *          - fun(arg, ...)会出现在表达式中，通过返回值的方式区分是否发生异常
 *              - 不符合编写程序的习惯
 *              - 可能发生多种一场通过返回值判断也很麻烦
 *  - 需要一种手段
 *      - 把异常与函数的接口分开，并且能够区分不同的异常
 *      - 在函数体外捕获所发生的异常，并提供更多信息
 * */
// #define eg_exception_throw
// #define eg_exception_rethrow
#define eg_standard_exception
#ifdef eg_exception_throw
#include <iostream>
using namespace std;
int main()
{
    double m, n;
    cin >> m >> n;
    try {
        cout << "before dividing." << endl;
        if(n==0)
            throw -1;//抛出int型异常
        else if(m==0)
            throw -1.0; //抛出double型异常
        else
            cout << m/n << endl;
        cout << "after dividing." << endl;
    }
    catch (double d)
    {
        cout << "catch(double)" << d << endl;
    }
    catch(int e)//throw -1会被这个catch捕捉
    {
        cout << "catch(int)" << e << endl;
    }
    cout << "finished" << endl;
    return 0;
}
#elif defined eg_exception_rethrow
/*
 * 若一个函数在执行过程中，抛出的异常在本函数内就被catch块捕获并处理了，那么改异常就不会抛给这个函数的调用者（也称上一层函数）
 * 如果异常在本函数中没有被处理，就会被抛给上一层函数。
 * */
#include <iostream>
#include <string>
using namespace std;
class CException
{
public:
    string msg;
    CException(string msg_)
        : msg(msg_)
    {}
};
double Divide(double x, double y)
{
    if (y == 0)
        throw CException(">>>divided by zero<<<");//只抛出，不处理
    cout << "in Divide" << endl;
    return x / y;
}
int CountTax(int salary)
{
    try {
        if (salary < 0)
            throw -1;
        cout << "counting tax" << endl;
    }
    catch (int) {
        cout << "salary < 0" << endl;
    }
    cout << "tax counted" << endl;
    return static_cast<int>(salary * 0.15);
}
int main()
{
    double f = 1.2;
    try{
        CountTax(-1);
        f = Divide(3,0);
        cout << "end of try block" << endl;
    }
    catch (CException &err) { //在这里处理Divide抛出的异常
        cout << err.msg << endl;
    }
    cout << "f=" << f << endl;//f的值仍为1.2
    cout << "finished" << endl;
    return 0;
}
#elif defined eg_standard_exception
/*
 * c++标准异常类
 *  - C++标准库中有一些类代表异常，这些类都是从exception类中派生而来的。常用的几个异常类如下:
 *      - bad_typeid
 *      - bad_cast
 *      - bad_alloc
 *      - ios_base::failure
 *      - logic_error --> out_of_range
 *
 * */
// #define eg_bad_cast
// #define eg_bad_alloc
#define eg_out_of_range
#ifdef eg_bad_cast
//在用dynamic_cast进行从多态基类对象（或引用），到派生类的引用的强制类型转换时，若果转换时不安全的 ，则会抛出异常
#include <iostream>
#include <stdexcept>
#include <typeinfo>
using namespace std;
class Base
{
    virtual void func(){}
};
class Derived : public Base
{
public:
    void Print(){}
};
void PrintObj(Base&b)
{
    try{
        Derived& rd = dynamic_cast<Derived&>(b);
        //此转换若不安全则会抛出bad_cast异常
        rd.Print();
    }
    catch (bad_cast& e){
        cerr << e.what() << endl;
    }
}
int main(int argc, char* argv[])
{
    Base b;
    PrintObj(b);
    //输出 std::bad_cast
    return 0;
}
#elif defined eg_bad_alloc
#include <iostream>
#include <stdexcept>
using namespace std;
int main(int argc, char* argv[])
{
    try {
        char* p = new char[0x7ffffffffff];//无法分配这么多空间，会抛出异常
    }
    catch (bad_alloc& err)
    {
        cerr << err.what() << endl;
    }
    //输出std::bad_alloc
    return 0;
}
#elif defined eg_out_of_range
//用vector或string的at成员函数根据下标访问元素时，如果下标越界，就会抛出异常。例如：
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
using namespace std;
int main(int argc, char* argv[])
{
    vector<int> v(10);
    try{
        v.at(100) = 100;//抛出out_of_range异常
    }
    catch (out_of_range& err) {
        cerr << err.what() << endl;
    }
    //输出 vector::_M_range_check: __n (which is 100) >= this->size() (which is 10)
    return 0;
}
#else
    #error "please uncomment macros accordingly"
#endif
#else
    #error "please uncomment macros accordingly"
#endif