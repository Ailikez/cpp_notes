/*
    * 基类的protected成员也已被以下函数访问:
    *   - 基类的成员函数
    *   - 基类的友元函数
    *   - 派生类的成员函数可以访问‘当前对象’的基类保护成员
*/
class Base
{
private:
    int nPri = 0;
public:
    int nPub = 0;
    int i = 0;
protected:
    int nPro = 0;
};
class Derived: public Base
{
public:
    int i = 0;
    void AccessBase()
    {
        i = 1;//ok
        Base::i = 1;//ok
        nPub = 1;
        //nPri = 1;// wrong;
        nPro = 1;
        Derived tmp;
        //tmp.nPro = 0;//wrong, tmp不是当前对象

    }
};
int main()
{

    Derived d;
    Base b;
    d.Base::i = 1;//ok
    d.nPub = 1;//ok
    b.nPub = 1;//ok
    //d.nPro = 1;//wrong
    //d.nPri = 1;//wrong
    //b.nPri = 1;//wrong
    //b.nPro = 1;//wrong

    return 0;
}