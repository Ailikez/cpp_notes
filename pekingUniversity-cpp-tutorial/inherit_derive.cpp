/*
    * 继承： 在定义一个新类B时，如果该类与某个已有的类A类似（B具有A的全部特点）
    *   则A可以作为一个基类，把B作为基类的派生类(子类)
    * 派生类一经定义后，独立于基类，可单独使用
    * 派生类是通过对基类进行修改和扩充得到的，可以扩充新的成员变量和成员函数
    * 派生类具有基类的所有成员变量和成员函数，不论公私有
    *   但是派生类中的各个成员函数中不能访问基类的private成员
    * 派生类写法 class 类名: public 基类名 {...}
    * 派生类对象的内存空间
    *   派生类对象的体积，等于基类对象的体积，再加上派生类对象自己的成员变量的体积。
    *   在派生类对象中，包含着基类对象
    *   而且基类对象的存储位置位于派生类对象新增的成员变量之前
    *   见例子CBase/CDerive
*/
#include <string>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
class CBase
{
    int v1, v2;
};
class CDerive: public CBase
{
    int v3;//v1 v2 在 v3之前
};
class CStudent
{
private:
    string name;
    string id;
    char gender;//性别
    int age;
public:
    void PrintInfo();
    void SetInfo(const string& name_,
                 const string& id_,
                 int age_,
                 char gender_);
    string GetName()
    { return name; }

};
void CStudent::PrintInfo()
{
    cout << name << ",\n" << id << ",\n" << gender << ",\n" << age << ",\n";
}
void CStudent::SetInfo(const string& name_,
                       const string& id_,
                       int age_,
                       char gender_)
{
    name = name_;
    id = id_;
    age = age_;
    gender = gender_;
}
class CUndergraduateStudent: public CStudent
{
private:
    string department;//所在系
public:
    void QualifiedForBaoYan()
    { cout << ">>>qualified for graduate recommendation<<<" << endl; }
    void PrintInfo()
    {
        CStudent::PrintInfo();//调用基类的方法
        cout << "Department: " << department << endl;
    }
    void SetInfo(const string& name_,
                 const string& id_,
                 int age_,
                 char gender_,
                 const string& department_)
    {
        CStudent::SetInfo(name_, id_, age_, gender_);
        department = department_;
    }
};
int main()
{
    CUndergraduateStudent s2;
    s2.SetInfo("HarryPotter", "2015050101018", 19, 'M', "Magic and Science");
    cout<<s2.GetName()<<'\n';
    s2.QualifiedForBaoYan();
    s2.PrintInfo();
    return 0;
}