#include <cstring>
class CArray
{
private:
    int size;//数组元素个数
    int *ptr;//指向动态分配的内存
public:
    CArray(int s = 0);//构造函数，s代表数组元素个数
    CArray(CArray &a);//复制构造函数
    CArray &operator=(const CArray &a);//数组对象间的赋值,深拷贝
    int &operator[](int i)
    { return ptr[i]; }//但从返回值类型来看，可以是int&或int，但返回值不是引用的话，不支持a[i]=4这种语句啊
    ~CArray();//析构
    void push2tail(int v);//在尾部添加元素
    int length()
    { return size; }
};
CArray::CArray(CArray &a)
{
    if (!a.ptr)
    {
        ptr = nullptr;
        size = 0;
        return;
    }
    ptr = new int[a.size];
    memcpy(ptr, a.ptr, sizeof(int) * a.size);
    size = a.size;
}
CArray &CArray::operator=(const CArray &a)
{
    //本函数的作用是使等号左边的对象里的数组的大小和内容变成等号右边的对象里的数组的大小和内容
    if (a.ptr == ptr)//防止a=a出错
        return *this;//遵循习惯，尽量使特性和运算符=相同
    if (a.ptr == nullptr)
    {
        if (ptr)
            delete[]ptr;
        ptr = nullptr;
        size = 0;
        return *this;
    }
    //判断是否需要新开辟空间
    if (size < a.size)//原有空间不够
    {
        if (ptr)
            delete[]ptr;//回收旧空间
        ptr = new int[a.size];//开辟新空间
    }
    memcpy(ptr, a.ptr, sizeof(int) * a.size);//复制
    size = a.size;
    return *this;
}
CArray::~CArray()
{
    if (ptr)
        delete[](ptr);
}
void CArray::push2tail(int v)
{
    if (ptr)
    {
        int *tmpPtr = new int[size + 1];
        memcpy(tmpPtr, ptr, sizeof(int) * size);
        delete[]ptr;
        ptr = tmpPtr;
    }
    else
        ptr = new int[1];
    ptr[size++] = v;//使用后统一加一
}
CArray::CArray(int s)
    : size(s)
{
    if (!s)
        ptr = nullptr;
    else
        ptr = new int[s];
}

