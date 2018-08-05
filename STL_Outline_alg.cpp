/*
    * 算法简介，算法就是一个个函数模板，大多数在<algorithm>中定义
    *   STL中提供能在各种容器中通用的算法，比如查找，排序等等
    *   算法通过迭代器来操纵容器中的元素。许多算法可以对容器中的一个局部空间进行操作，因此需要两个参数，一个是
    *       其实元素的迭代器，一个是终止元素的后面一个元素的迭代器。比如排序和查找
    *   有的算法返回一个迭代器。比如find()算法，在容器中查找一个元素并返回一个指向该元素的迭代器
    *   算法也可以处理容器，也可以处理普通数组
    * 算法示例：find()
    *   template<class init, class T>
    *   init find(init first, init last, const T& val);
    *   - first 和 last 这两个参数都是容器的迭代器，他们给出了容器中的查找区间起点和终点[first, last).
    *       区间的起点是位于查找范围之中的而终点不是。find()在[first, last)里面查找等于val的元素
    *   - 用==运算符判断相等
    *   - 函数返回值是一个迭代器。如果找到，则该迭代器指向被找到的元素。如果找不到，则该迭代器等于last
    * STL中 “大” “小” 的概念
    *   - 关联容器内部的元素是从小到大排序的
    *   - 有些算法要求其操作的区间是从小到大排序的，称为“有序区间算法”，例如binary_search
    *   - 有些算法会对区间进行从小到大排序，称为排序算法，例如sort
    *   - 还有一些其他算法会用到“大”“小”的概念
    *       使用STL时，在缺省情况下，以下三个说法等价：
    *           1.x比y小
    *           2.表达式“x<y”为真
    *           3.y比x大
    * STL中相等的概念
    *   - 有时，“x和y相等” 等价于 “x==y为真”， 比如在未排序的空间上进行的算法，如顺序查找find
    *   - 有时，“x和y相等” 等价于 “x小于y 和 y小于x 同时为假”
    *       例：有序空间算法，比如binary_search; 关联容器自身的成员函数find
    *
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//STL中相等的概念演示
class A
{
public:
    A(int n)
        : v(n)
    {}
    bool operator<(const A &a2) const
    {
        cout << v << "<" << a2.v << "?" << "false" << endl;
        return false;//任何两个class A对象，其中一个都不会小于另外一个
    }
    bool operator==(const A &a2) const
    {
        cout << v << "==" << a2.v << "?" << endl;
        return v == a2.v;
    }
private:
    int v;
};
int main(int argc, char *argv[])
{
    int array[10] = {10, 20, 30, 40};
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    vector<int>::iterator p;
    p = find(v.begin(), v.end(), 3);
    if (p != v.end())
        cout << *p << endl;//应该输出3
    p = find(v.begin(), v.end(), 9);
    if (p == v.end())
        cout << "not found" << endl;
    p = find(v.begin() + 1, v.end() - 2, 1);//整个容器[1,2,3,4], 查找区间[2,3)
    if (p != v.end())//没找到，所以p==v.end()-2
        cout << *p << endl;//这里输出3
    int *pp = find(array, array + 4, 20);//普通数组名称是迭代器
    cout << *pp << endl;
    //STL中相等的概念演示
    A a[] = {A(1), A(2), A(3), A(4), A(5)};
    cout << binary_search(a, a + 4, A(9));//折半查找，输出结果为1，明明没有A(9)却说找到了
    //再看一下输出，binary_search调用的全部是operator<成员函数
    //binary_search比较与A(9)是否相等，是用的 “x和y相等” 等价于 “x小于y 和 y小于x 同时为假”这一条
    return 0;
}