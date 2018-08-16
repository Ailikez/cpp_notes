//可变长动态数组vector
/*
    * 必须包含头文件<vector>
    * 支持随机访问迭代器
    *   - 根据下标随机访问某个元素时间为常数
    *   - 在尾部添加元素速度很快
    *   - 在中间插入元素慢
    * 所有STL算法都可以作用到vector上
    * vector的成员函数
    *   - 构造函数初始化
    *       - vector();             无参构造函数，将容器初始化为空
    *       - vector(int n);        将容器初始化成有n个元素
    *       - vector(int n, const T& val); 假定元素类型是T，将容器初始化成有n个元素，所有值都为val
    *       - vector(iterator first, iterator last);将容器初始化为与别的容器上的区间[fisrt,last)
    *           内一致的内容
    *   - 其他常用函数
    *       - void pop_back();      删除容器末尾的元素
    *       - void push_back(const T& val); 将val添加到容器末尾
    *       - int size();   返回容器中元素的个数
    *       - T& front();   返回容器中第一个元素的引用
    *       - T& back();    返回容器中最后一个元素的引用
    *
*/
#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char *argv[])
{
    int i;
    int a[5] = {1, 2, 3, 4, 5};
    vector<int> v(5);//初始化为有5个元素的容器
    cout << v.end() - v.begin()<< endl;//两个随机访问器可以相减
    for (i = 0; i < v.size(); ++i) {
        v[i] = i;//[]重载，随机访问
    }
    v.at(4) = 100;
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << ",";
    }
    cout << endl;
    vector<int> v2(a, a+5);//最后一个构造函数，传入两个迭代器构成区间
    v2.insert(v2.begin()+2, 13);//在v2.begin()+2位置插入13
    for (int i = 0; i < v2.size(); ++i) {
        cout << v2.at(i) << ",";
    }
    cout << endl;
    //二维动态数组
    vector<vector<int>> v3(3);//v有三个元素，每个元素都是一个vector<int>容器
    for (int i = 0; i < v3.size(); ++i)
        for (int j = 0; j < 4; ++j)
            v3[i].push_back(j);
    for (int i = 0; i < v3.size(); ++i) {
        for (int j = 0; j < v3[i].size(); ++j)
            cout << v3[i][j] << " ";
        cout << endl;
    }
    return 0;
}