/*
 * STL算法分类-大致以下7类
 *      - 不变序列算法
 *          - 该类算法不会修改算法所作用的容器或者对象
 *          - 适用于顺序容器和关联容器
 *          - 时间复杂度都是O(n),要遍历
 *          - 算法举例
 *              - min               求两个对象中较小的（可自定义比较器）
 *              - max               求两个对象中较大的（可自定义比较器）
 *              - min_element       求区间中最小值（可自定义比较器）
 *                  template<class FwdIt>
 *                  FwdIt min_element(FwdIt first, FwdIt last);
 *                  返回[first,last)中元素最小的迭代器，以"<"作比较器
 *                  最小值没有元素比它小，而不是它比所有元素都小，
 *                  因为即便a!=b, a<b和b<a有可能都不成立。
 *              - max_element       求区间中最大值（可自定义比较器）
 *                  template<class FwdIt>
 *                  FwdIt max_element(FwdIt first, FwdIt last);
 *                  返回[first,last)中最大元素(不小于其他元素)的迭代器，以"<"作比较器
 *              - for_each          对区间中每个元素都执行某种操作
 *                  template<class Init, class Fun>
 *                  Fun for_each(Init first, Init last, Fun f);
 *                  对[first, last)中的每个元素e，执行f(e),要求f(e)不能改变e
 *              - count             计算区间内等于某值的元素个数==
 *                  template<class Init, class T>
 *                  size_t count(Init first, Init last, const T& val);
 *                  计算[first, last)中等于val的元素个数(x==y值为true算等于)
 *              - count_if          计算区间内符合某种条件的元素个数
 *                  template<class Init, class Pred>
 *                  size_t count_if(Init first, Init last, Pred pr);
 *                  计算[first, last)中符合 pr(e)==true 的元素e的个数
 *
 *              - find              在区间内查找等于某元素的值==
 *                  template<class Init, class T>
 *                  Init find(Init first, Init last, const T& val);
 *                  返回区间[first, last)中的迭代器i，使得 *i == val
 *
 *              - fnd_if            在区间内查找复合某条件的元素
 *                  template<class Init, class Pred>
 *                  Init find_if(Init first, Init last, Pred pr);
 *                  返回区间[first, last)中的迭代器i，使得 pr(*i) == true
 *              - find_end          在区间内查找另一个区间最后一次出现的位置(可自定比较器)
 *              - find_first_of     在区间内查找第一个出现在另一个区间内的元素(可自定义比较器)
 *              - adjacent_find     在区间内寻找第一次出现连续两个相等元素的位置(可自定义比较器)
 *              - search            在区间中查找另一个区间第一次出现的位置(可)
 *              - search_n          在区间中查找第一次出现等于某值的连续n个元素（可）
 *              - equal             判断两区间是否相等（可）
 *              - mismatch          逐个比较两个区间的元素，返回第一次发生不相等的两个元素的位置(可)
 *              - lexicographical_compare 按照字典比较两个区间的大小（可）
 *      - 变值算法
 *          - 此类算法会修改源区间或者目标区间元素的值
 *          - 值被修改的那个区间，不可以是属于关联容器的
 *          - 算法举例
 *              - for_each          对区间中的每个元素都做某种操作
 *              - copy              复制一个区间到别处
 *                  template<class Init, class OutIt>
 *                  OutIt copy(Init first, Init last, OutIt x);
 *                  - 本函数对每个区间[0, last - first)中的N执行一次
 *                      *(x + N) = *(first + N), 返回x + N
 *                  - 对于下面的copy(v.begin(), v.end(), output)
 *                      - first和last的类型是vector<int>::const_iterator
 *                      - output的类型是ostream_iterator<int>
 *                  - copy的源代码
 *                      tmplate <class _II, class __OI>
 *                      inline _OI copy(__II _F, __II _L, __OI _X)
 *                      {
 *                          for(;_F != _L; ++_X,++_F)
 *                              *_X = *_F;
 *                          return(_X);
 *                      }
 *              - copy_backward     赋值一个区间到别处，但目标区间是从后往前被修改的
 *              - transform         将一个区间的元素变形后拷贝到另一个区间
 *                  template<class Init, class OutIt, class Unop>
 *                  OutIt transform(Init first, Init last, OutIt x, Unop uop);
 *                  - 对[first, last)中每个迭代器i
 *                      - 执行uop(*i)并将结果依次放入从x开始的地方
 *                      - 要求uop(*i)不得改变*i的值
 *                  - 本模板返回值是个迭代器，即 x + (last - first)
 *                      - x和first可以相等
 *              - swap_ranges
 *              - fill
 *              - fill_n
 *              - generate
 *              - generate_n
 *              - replace
 *              - replace_if
 *              - replace_copy
 *              - replace_copy_if
 *      - 删除算法
 *          - 删除一个容器中的某些元素
 *          - 删除 -- 不会使容器中的元素减少
 *              - 将所有应该被删除的元素看作空位子
 *              - 用留下的元素从后往前移，依次去填空位子
 *              - 元素往前移后，它原来的位置也就算是空位子
 *              - 也应该由后面的留下的元素来填上
 *              - 最后没有被填上的空位子维持其原来的值不变
 *          - 删除算法不应该用作关联容器
 *          - 算法举例
 *              - remove            删除区间中等于某值的元素
 *              - remove_if         删除区间中满足某种条件的元素
 *              - remove_copy       拷贝区间到另一个区间，等于某个值的元素不拷贝
 *              - remove_copy_if    拷贝区间到另一个区间，符合某种条件的元素不拷贝
 *              - unique            删除区间中连续相等的元素，只留下一个（可自定义比较器）
 *                  - 1.用==比较是否相等
 *                  - 2.用Pred pr, pr(x,y)为true，则xy相等
 *                  - 对[first, last)这个序列中连续相等的元素，只留下最后一个
 *                  - 返回迭代器，指向元素删除后的区间的最后一个元素的后面
 *              - unique_copy       拷贝区间到另一个区间，连续相等的元素，只拷贝第一个（可）
 *          - 算法复杂度均是O(n)
 *      - 变序算法
 *          - 变序算法改变容器中元素的顺序
 *          - 不改变元素的值
 *          - 变序算法不适用于关联容器
 *          - 算法复杂度都是O(n)
 *          - 算法举例
 *              - reverse       颠倒区间的前后次序
 *              - reverse_copy  把一个区间颠倒后的结果拷贝到另一个区间，源区间不变
 *              - rotate        将区间进行循环左移
 *              - rotate_copy   将区间以首尾相接的形式进行旋转后的结果拷贝到另外一个区间，源区间不变
 *              * next_permutation  将区间改为下一个排列(可自定义比较器)
 *              * prev_permutation  将区间改为上一个排列（可自定义比较器）
 *              * random_shuffle    随机达伦区间内元素顺序
 *                  template<class RanIt>
 *                  void random_shuffle(RanIt first, RanIt last);
 *              - partition     把区间内满足某个条件的元素移到前面，不满足的移到后面
 *              * stable_partition 把区间内满足某个条件的元素移到前面，不满足的移到后面, 相对顺序不变
 *      - 排序算法
 *          - 比前面的变序算法复杂度更高，一般是O(nlog(n))
 *          - 排序算法需要随机访问迭代器的支持，所以list不能使用sort算法要使用list::sort
 *          - 不适用于关联容器和list
 *          - 算法举例
 *              - sort              将区间从小到大排列（可）
 *                  template<class RanIt>
 *                  void sort(RanIt first, RanIt last);
 *                  - 按升序排列
 *                  - 判断x是否应该比y靠前，就看x<y是否为true
 *                  template<class RanIt, class Pred>
 *                  void sort(RanIt first, RanIt last, Pred pr);
 *                  - 按升序排列
 *                  - 判断x是否应该比y靠前，就看pr(x,y)是否为true
 *                  * sort实际上是快速排序，时间复杂度O(n*log(n))
 *                      * 平均性能最优
 *                      * 但在最坏情况下，性能可能非常差
 *
 *              - stable_sort       将区间从小到大排列，并保持相等元素间的相对次序(可)
 *                  * 如果要保证最坏情况下的性能，那么可以使用stable_sort
 *                  * stable_sort实际上是归并排序，特点是能保持相等的元素之间的先后次序
 *                  * 在有足够存储空间的情况下，复杂度为nlog(n),否则复杂度为nlog(n)log(n)
 *                  * 用法同sort
 *
 *              - partial_sort      对区间部分排序，直到最小的n个元素就位（skr）
 *              - partial_sort_copy 将区间前n个元素的排序结果拷贝到别处，源区间不变（可）
 *              - nth_element       对区间部分排序，使得第n小的元素（n从0开始算）就位，而且比它小的都在它前面，
 *                                  比它大的都在它后面（可）
 *              - make_heap         使区间变成一个堆（可）
 *              - push_heap         将元素加入一个是堆的区间（可）
 *              - pop_heap          从对区间删除堆顶元素（可）
 *              - sort_heap         将一个堆区间进行排序，排序结束后变成普通有序区间，不再是堆（可）
 *      - 有序区间算法
 *          - 要求所操作区间是已经从小到大排好序的
 *          - 需要随机访问迭代器的支持
 *          - 有序区间算法不能用于关联容器和list
 *          - 算法举例
 *              - binary_search     判断区间内是否包含某个元素
 *                  - 折半查找/log(n)
 *                  - 要求容器已经有序且支持随机访问迭代器，返回是否找到
 *                  template<class FwdIt, class T>
 *                  bool binary_search(FwdIt first, FwdIt last, const T& val);
 *                  - 上面这个版本，比较x、y大小时，看x<y
 *                  template<class FedIt, class T, class Pred>
 *                  bool binary_search(FwdIt first, FwdIt last, const T& val, Predpr);
 *                  - 这个版本，比较元素x，y大小时，若pr(x,y)为true, 则x<y
 *              - includes          判断是否一个区间内的每个元素，都在另一个区间内
 *                   tempalte<class InIt1, class InIt2>
 *                   bool includes(InIt first1, InIt last1, InIt first2, InIt last2);
 *                  - 上面用 < 做比较器
 *                  tempalte<class InIt1, class InIt2, class Pred>
 *                  OutIt merge(InIt first1, InIt last1, InIt first2, InIt last2, Pred pr);
 *                  - 用pr做比较器，为true相等
 *                  - 判断[first2, last2)中的元素是否都在[first1, last1)里面
 *              - lower_bound       查找最后一个不小于某值的元素的位置
 *                  template<class FwdIt, class T>
 *                  FwdIt lower_bound(FwdIt first, FedIt last, const T& val);
 *                  - 要求[first, last)有序
 *                  - 查找[first,last)中的，最大的位置FwdIt，使得[first,last)中所有元素都比val小
 *              - upper_bound       查找第一个大于某值的元素的位置
 *                  template<class FwdIt, class T>
 *                  FwdIt upper_bound(FwdIt first, FedIt last, const T& val);
 *                  - 要求[first, last)有序
 *                  - 查找[first,last)中的，小最的位置FwdIt，使得[first,last)中所有元素都比val大
 *              - equal_range       同时获取lower_bound和upper_bound
 *                  template<class FwdIt, class T>
 *                  pair<FwdIt, FwdIt> equal_range(FwdIt first, FwdIt last, const T& val);
 *                  - 要求[first, last)有序
 *                  - 返回值是pair, 假设为p，则：
 *                      * [first, p.first)中的元素都比val小
 *                      * [p.second, last)中的所有元素都比val大
 *                      * p.first就是lower_bound的结果
 *                      * p.second就是upper_bound的结果
 *              - merge             合并两个有序区间到第三个区间
 *                  tempalte<class InIt1, class InIt2, class OutIt>
 *                  OutIt merge(InIt first1, InIt last1, InIt first2, InIt last2, OutIt x);
 *                  - 上面用 < 做比较器
 *                  tempalte<class InIt1, class InIt2, class OutIt, class Pred>
 *                  OutIt merge(InIt first1, InIt last1, InIt first2, InIt last2, OutIt x, Pred pr);
 *                  - 用pr做比较器
 *                  - 把[first1, last1),[first2, last2)两个升序序列合并，形成第3个升序序列，第三个升序序列以x开头
 *              - set_union         把两个有序区间的 并 拷贝到第三个区间
 *                  tempalte<class InIt1, class InIt2, class OutIt>
 *                  OutIt set_union(InIt first1, InIt last1, InIt first2, InIt last2, OutIt x);
 *                  - 上面用 < 做比较器
 *                  tempalte<class InIt1, class InIt2, class OutIt, class Pred>
 *                  OutIt set_union(InIt first1, InIt last1, InIt first2, InIt last2, OutIt x, Pred pr);
 *                  - 用pr做比较器
 *                  - 求两个区间的并，放到x开始的位置
 *                  - 如果某个元素e在[first1, last1)中出现n1次，在[first2,last2)中出现n2次，
 *                    则该元素在目标区间里出现max(n1,n2)次
 *              - set_intersection  交
 *                  tempalte<class InIt1, class InIt2, class OutIt>
 *                  OutIt set_intersection(InIt first1, InIt last1, InIt first2, InIt last2, OutIt x);
 *                  - 上面用 < 做比较器
 *                  tempalte<class InIt1, class InIt2, class OutIt, class Pred>
 *                  OutIt set_intersection(InIt first1, InIt last1, InIt first2, InIt last2, OutIt x, Pred pr);
 *                  - 用pr做比较器
 *                  - 求出[first1, last1)和[first2, last2)中共有的元素，放到从x开始的地方
 *                  - 如果某个元素e在[first1, last1)中出现n1次，在[first2,last2)中出现n2次，
 *                    则该元素在目标区间里出现min(n1,n2)次
 *              - set_difference    差
 *                  tempalte<class InIt1, class InIt2, class OutIt>
 *                  OutIt set_dfference(InIt first1, InIt last1, InIt first2, InIt last2, OutIt x);
 *                  - 上面用 < 做比较器
 *                  tempalte<class InIt1, class InIt2, class OutIt, class Pred>
 *                  OutIt set_dfference(InIt first1, InIt last1, InIt first2, InIt last2, OutIt x, Pred pr);
 *                  - 用pr做比较器
 *                  - 求出[first1, last1)中，不再[first2, last2)中的元素，放到从x开始的地方
 *                  - 如果[first1, last1)中有多个相等元素不再[first2,last2)中，则这多个元素也都会被放入x代表的目标区间里
 *              - set_symmetric_difference 并减去交
 *                  tempalte<class InIt1, class InIt2, class OutIt>
 *                  OutIt set_symmetric_difference(InIt first1, InIt last1, InIt first2, InIt last2, OutIt x);
 *                  - 上面用 < 做比较器
 *                  tempalte<class InIt1, class InIt2, class OutIt, class Pred>
 *                  OutIt set_symmetric_difference(InIt first1, InIt last1, InIt first2, InIt last2, OutIt x, Pred pr);
 *                  - 用pr做比较器
 *                  - 把两个区间里互相不再另一区间里的元素放入x开始的地方
 *              - inplace_merge
 *      - 数值算法
 *      - bitset
 *          template<size_t N>
 *          class bitset
 *          {...};
 *          - 实际使用时，N是个整型常数
 *          - 如：
 *              - bitset<40> bst;
 *              - bst 是一个由40位组成的对象
 *              - 用bitset的函数可以方便地访问任何一位
 *          - 成员函数一大堆
 * - 大多重载的算法都是有两个版本的
 *      - 用 == 判断元素是否相等，或者用 < 来比较大小
 *      - 多出一个类型参数Pred和函数形参Pred op
 *          通过表达式 op(x,y)返回的值：true/false判断x是否小于/等于y
 *      - 如下有两个版本的min_element
 *          iterator min_element(iterator first, iterator last);//小于号比大小
 *          iterator min_element(iterator first, iterator last, Pred op);//op比较大小
 *
 *
 * */

//#define eg_unchanged_value
//#define eg_changed_value
//#define eg_delete_algo
//#define eg_variable_order_algo
//#define eg_sorting_algo
#define eg_order_interval
#ifdef eg_unchanged_value
#include <algorithm>
#include <iostream>
using namespace std;
class A
{
public:
    int n;
    A(int n_)
        : n(n_)
    {}
};
bool operator<(const A& a1, const A& a2)
{
    cout << "operator< called" << endl;
    if(a1.n == 3 && a2.n ==7)//只有3<7的情况是true
        return true;
    else
        return false;
}
int main(int argc, char* argv[])
{
    A aa[] = {3,5,7,2,1};
    cout << min_element(aa, aa+5)->n << endl;
    //先假定3为最小值，拿之后的元素和3依次比较，5<3,7<3,2<3,1<3,全部为假，所以3为最小，输出3
    cout << max_element(aa, aa+5)->n << endl;
    //先假定3为最大值，3<5 false, 3<7 true, 这里最大值换成7,再比较7<2 false, 7<1 false
    return 0;
}
#endif
#ifdef eg_changed_value
#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <list>
#include <iterator>
#include <string>
using namespace std;
template<typename T>
class My_ostream_iterator/*要写后面的才行*/:public iterator<output_iterator_tag, T>
{
//该类用来解释ostream_iterator<int> output(cout, " ");
//copy(v.begin(), v.end(), output);//导致v的内容再cout上输出
public:
    string s;
    ostream& o;
    My_ostream_iterator(ostream &o_, string s_)
        : o(o_), s(s_)
    {}
    My_ostream_iterator& operator=(const T& tmp)//按照惯例，返回引用
    {
        o << tmp << s;
        return *this;
    }
    My_ostream_iterator& operator* ()//没必要写<T>
    {
        return *this;
    }
    void operator++()//编译能过就行
    {
        return;
    }
};
class CLessThan9//函数对象类
{
public:
    bool operator()(int n)
    { return n < 9; }
};
void outputSquare(int value)
{ cout << value * value << " "; }
int calculateCube(int value)
{ return value * value * value; }
int main(int argc, char *argv[])
{
    constexpr int SIZE = 10;
    int a1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int a2[] = {100, 2, 8, 1, 50, 3, 8, 9, 10, 2};
    vector<int> v(a1, a1 + SIZE);
    ostream_iterator<int> output(cout, " ");
    //定义了一个ostream_iterator<int> 对象，可以通过cout输出以空格分隔的一个个整数
    random_shuffle(v.begin(), v.end());//伪随机打乱
    cout << endl << "1)";
    copy(v.begin(), v.end(), output);//导致v的内容再cout上输出
    copy(a2, a2 + SIZE, v.begin());
    cout << endl << "2)";
    cout << count(v.begin(), v.end(), 8);
    cout << endl << "3)";
    cout << count_if(v.begin(), v.end(), CLessThan9());//CLessThan9()是个对象
    cout << endl << "4)";
    cout << *(min_element(v.begin(), v.end()));
    cout << endl << "5)";
    cout << *(max_element(v.begin(), v.end()));
    cout << endl << "6)";
    cout << accumulate(v.begin(), v.end(), 0);
    cout << endl << "7)";
    for_each(v.begin(), v.end(), outputSquare);
    vector<int> cubes(SIZE);
    transform(a1, a1 + SIZE, cubes.begin(), calculateCube);
    cout << endl << "8)";
    copy(cubes.begin(), cubes.end(), output);

    My_ostream_iterator<int> o2(cout, "*");
    copy(cubes.begin(), cubes.end(), o2);

    return 0;
}
#endif
#ifdef eg_delete_algo
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
int main(int argc, char *argv[])
{
    int a[5] = {1, 2, 3, 2, 5};
    int b[6] = {1, 2, 3, 2, 5, 6};
    ostream_iterator<int> oit(cout, ",");
    int *p = remove(a, a + 5, 2);//remove无法使元素元素个数变少
    cout << "1)";
    copy(a, a + 5, oit);//输出1,3,5,2,5,因为剩下的空位子保持不变所以最后是2,5
    cout << endl;
    cout << "2)" << p - a << endl;//删除之后剩余的有效元素个数
    vector<int> v(b, b + 6);
    remove(v.begin(), v.end(), 2);
    cout << "3)";
    copy(v.begin(), v.end(), oit);
    cout << endl;
    cout << "4)";
    cout << v.size() << endl;
    return 0;
}
#endif
#ifdef eg_variable_order_algo
#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <iterator>
using namespace std;
int main()
{
    string str = "231";
    char szStr[] = "324";
    while (next_permutation(str.begin(), str.end()))//找下一个排列
        cout << str << endl;
    cout << "********" << endl;
    while (next_permutation(szStr, szStr + 3))
        cout << szStr << endl;
    sort(str.begin(), str.end());
    cout << "********" << endl;
    while (next_permutation(str.begin(), str.end()))
        cout << str << endl;

    int a[] = {8, 7, 10};
    list<int> lst(a, a + 3);
    while (next_permutation(lst.begin(), lst.end())) {
        list<int>::iterator i;
        for (i = lst.begin(); i != lst.end(); ++i)
            cout << *i << " ";
        cout << endl;
    }
    return 0;
}
#endif
#ifdef eg_sorting_algo
#include <iostream>
#include <algorithm>
using namespace std;
class MyLess
{
public:
    bool operator()(int n1, int n2)
    {
        return (n1 % 10) < (n2 % 10);
    }
};
int main()
{
    int a[] = {14,2,9,111,78};
    sort(a,a+5,MyLess());
    int i;
    for(i=0;i<5;++i)
        cout << a[i] <<" ";
    cout<<endl;
    sort(a,a+5,greater<int>());
    for(i=0;i<5;++i)
        cout << a[i] << " ";
    return 0;
}
#endif
#ifdef eg_order_interval
#include <vector>
#include <bitset>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <list>
#include <iterator>
using namespace std;
bool greater10(int n)
{ return n > 10; }
int main()
{
    constexpr int SIZE = 10;
    int a[] = {2, 8, 1, 50, 3, 100, 8, 9, 10, 2};
    vector<int> v(a, a + SIZE);
    ostream_iterator<int> output(cout, " ");
    vector<int>::iterator location;
    location = find(v.begin(), v.end(), 10);
    if (location != v.end())
        cout << endl << "1)" << location - v.begin();
    location = find_if(v.begin(), v.end(), greater10);
    if(location != v.end())
        cout << endl << "2)" << location - v.begin();
    sort(v.begin(), v.end());
    if(binary_search(v.begin(), v.end(), 9))
        cout << endl <<"3)" << "9 found";
    return 0;
};
#endif