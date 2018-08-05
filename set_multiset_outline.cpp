/*
    * set, multiset, map, multimap
    *   - 内部元素有序排列，新元素插入的位置取决于它的值，查找速度快。
    *   - 除了各容器都有的函数之外，还支持以下函数
    *       - find: 查找等于某个值的元素(x小于y和y小于x同时不成立为相等)
    *       - lower_bound: 查找某个下界
    *       - upper_bound: 查找某个上界
    *       - equal_range: 同时查找上界和下界
    *       - count: 计算等于某个值的元素个数(x小于y和y小于x同时不成立为相等)
    *       - insert: 用以插入一个元素或一个区间
*/
/*
    * pair模板
    * map/multimap容器里放的都是pair模板类的对象，而且按照first从小到大排列
*/
#include <iostream>
#include <set>
using namespace std;

/*----------------*/
/*     pair模板   */
/*---------------*/
template<typename _T1, typename _T2>
//struct更适合看成是一个数据结构的实现体，class更适合看成是一个对象的实现体
struct _pair
{
    typedef _T1 first_type;
    typedef _T2 second_type;
    _T1 first;
    _T2 second;
    _pair()//无参版ctor
        : first(), second()
    {}
    _pair(const _T1& __a, const _T2& __b)
        :
        first(__a), second(__b)
    {}
    template<class _U1, class _U2>
    _pair(const _pair<_U1, _U2>& __p)//__p是类对象的引用
        :first(__p.first), second(__p.second)
    {}
};
//第三个构造函数用法
_pair<int, int>
_p(_pair/*pair类模板*/<double, double>/*pair模板类*/(5.5, 4.6)/*实例化的临时对象*/);
//_p.first=5 _p.second=4

/*----------------*/
/*    multiset    */
/*----------------*/
/*
    先看一下multiset的定义
    template<class Key, class Pred = less<Key>
            class = >
*/
int main(int argc, char* argv[])
{

    return 0;
}