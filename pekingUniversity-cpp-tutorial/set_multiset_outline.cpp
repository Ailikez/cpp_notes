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
        template<class Key, class Pred = less<Key>,
                class = allocator<Key>>
        class multiset {....};
    - Pred类型的变量决定了multiset中的元素 ‘一个比另一个小’是怎么定义的。
        multiset运行过程中比较两个元素x，y大小的做法，就是生成一个Pred类型的
        变量，假定为op，若表达式op(x,y)返回值为true，则x比y小
        Pred缺省类型是less<Key>
    - less模板定义
        template<class T>
        struct less : public binary_function<T, T, bool>
        {bool operator()(const T& x, const T& y) {return x < y;} const;};
        //less模板靠<来比较大小
    - multiset的成员函数
        - iterator find(const T& val);
            在容器中查找值为val的元素，返回其迭代器，没有返回end()
        - iterator insert(const T& val);
            将val插入到容器中并返回其迭代器
        - void insert(iterator first, iterator last);
            将区间[first, last)插入容器
        - int count(const T& val);
            统计有多少个元素的值和val相等
        - iterator lower_bound(const T& val);//查找下界
            查找一个最大的位置it，使得[begin(), it)中的所有元素都比val小
        - iterator upper_bound(const T& val);//查找上界
            查找一个最小的位置it，使得[it,end())中的所有元素都比val大
        - pair<ierator, iterator> equal_range(const T& val);
            同时求得lower_bound和upper_bound.
        - iterator erase(iterator it);
            删除it指向的元素，返回其后面的元素的迭代器(vs2010上是这样,
            C++标准和Dev C++中，返回值不是iterator.)
*/
/* multiset用法示例 */
#include <set> //使用头文件<set>
class A{};
template <class T>
void Print(T first, T last)
{
    for(; first != last; ++first)
        cout << *first << " ";
    cout << endl;
}
class A1
{
private:
    int n;
public:
    A1(int n_):n(n_){}
    friend bool operator< (const A1& a1, const A1& a2)
    {return a1.n < a2.n;}
    friend ostream& operator<< (ostream& o, const A1& a)
    {o<<a.n; return o;}
    friend class MyLess;
};
struct MyLess
{
    bool operator() (const A1& a1, const A1& a2)
    {return ((a1.n % 10) < (a2.n % 10));/*按个位数比大小*/}
};
typedef multiset<A1> MSET1;//MSET1用<比较大小
typedef multiset<A1, MyLess> MSET2;//MSET2用MyLess::operator()比较大小
/*----------------*/
/*      set       */
/*----------------*/
/*
 * set
 *      template<class Key, class Pred = less<Key>,
 *              class A = allocator<Key>>
 *      class set{...};
 *      //插入set中已有元素时，自动忽略本次插入
 *
 * */
int main(int argc, char* argv[])
{
    multiset<A> a;
//    a.insert(A());//error
    //分析为什么会报错
    //multiset<A> a;等价于multiset<A, less<A>> a;
    //插入元素时，multiset会将被插入的元素和已有元素进行比较。由于less模板是用<进行比较的
    //所以，这要求A的对象必须能用<进行比较，也就是说适当重载了<,有operator<(const T& a)成员函数

    /*---------*/
    constexpr int SIZE = 6;
    A1 a1[SIZE] = {4,22,19,8,33,40};
    MSET1 m1;
    m1.insert(a1, a1+SIZE);
    m1.insert(22);
    cout << "1) " << m1.count(22) << endl;//输出  1) 2
    cout << "2) "; Print(m1.begin(), m1.end());//输出  2) 4 8 19 22 22 33 40
    MSET1::iterator pp = m1.find(19);
    if(pp != m1.end())//条件为真，则找到
        cout << "found 19" << endl;
    cout << "3) ";
    cout << *m1.lower_bound(22) << ","
         << *m1.upper_bound(22) << endl;// 3) 22,33
    pp = m1.erase(m1.lower_bound(22), m1.upper_bound(22));
    //pp指向被删除的元素的下一个元素
    cout << "4) ";Print(m1.begin(), m1.end());// 4) 4 8 19 33 40
    cout << "5) ";cout << *pp << endl;// 5) 33
    MSET2 m2;//m2里面的元素按n的个位数从小到大排列
    m2.insert(a1, a1 + SIZE);
    cout << "6) ";Print(m2.begin(), m2.end());
    /*----------------*/
    /*      set       */
    /*----------------*/
    typedef set<int>::iterator IT;
    int a2[5] = {3,4,6,1,2};
    set<int> st(a2, a2+5);//st里是12346
    pair<IT, bool> result;
    result = st.insert(5);//st变成123456
    if(result.second)//插入成功就输出被插入元素
        cout << ">>>" << *result.first << " inserted" << endl;
    if(st.insert(5).second)
        cout << *result.first << endl;
    else
        cout << ">>>inserted failed, "
             << *result.first << " already exists" << endl;
    pair<IT, IT> bounds = st.equal_range(4);
    cout << ">>>" << *bounds.first << "," << *bounds.second;// 4,5

    return 0;
}