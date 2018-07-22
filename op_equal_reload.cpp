/*
    * 赋值运算符只能重载为成员函数
    * 重载赋值运算符的意义-浅复制/深复制
    * 浅复制 -- 逐字节复制，S1=S2; s1.str指针和s2.str指针一样了，s1.str原来指向的内存变成辣鸡内存
    *   只复制指针值，会产生内存垃圾，而且消亡时同一块内存会被释放两次，导致严重内存错误
    * 深复制 -- 将一个对象中指针变量指向的内容复制到另一个对象中指针变量所指的内容
    * 运算符重载时，好的风格--尽量保留运算符原本的特性
*/

#include <iostream>
#include <cstring>
using std::cout;
using std::endl;
using std::cin;
//编写一个长度可变的字符串类型String
//为String类编写复制构造函数时，会面临和=相同的问题，也要用深拷贝
class String
{
private:
    char *str;
public:
    String()
        : str(nullptr)
    { cout << "String Class Constructor called." << endl; }
    const char *c_str()
    { return str; }
    char *operator=(const char *s);//深拷贝， 返回str指针
    String &operator=(const String &s);//深拷贝，返回引用
    String(String & s);//复制构造函数, 对应String s2(s1);这种情况
    ~String();
};

char *String::operator=(const char *s)
{
    if (str) delete[](str);
    if (s)//不为null才执行拷贝
    {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
    else
        str = nullptr;
    return str;
}
String::~String()
{
    if (str)
        delete[](str);
    cout << "String Class Destructor called." << endl;
}
String &String::operator=(const String &s)
{
    if (s.str == str)
        return *this;//预防出现s=s;
    if (str) delete[](str);
    if (s.str) {
        str = new char[strlen(s.str) + 1];
        strcpy(str, s.str);
    }
    else
        str = nullptr;
    return *this;
}
String::String(String &s)
{
    if(s.str)
    {
        str = new char[strlen(s.str) + 1];
        strcpy(str, s.str);
    }
    else
        str = nullptr;
}

int main()
{
    String s;
    s = "Good Luck!";
    cout << s.c_str() << endl;
    s = "Fuck you!";
    cout << s.c_str() << endl;
    return 0;
}