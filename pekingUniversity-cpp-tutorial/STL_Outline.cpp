/*
    * 标准模板库就是一些常用的数据结构和算法的模板的集合，性能挺高
    * 基本概念：
    *   - 容器：可以容纳各种类型数据的通用数据结构，是类模板
    *       1. 顺序容器 vector，deque，list
    *           - vector 头文件<vector>
    *               动态数组。元素在内存中连续存放。随机存取任何元素都能在 常数时间 完成。
    *               在尾端增删元素具有较佳的性能(大部分情况下是常数时间，要重新分配存储空间时o(n))
    *               （提前分配了较多的存储空间，分配空间满了要重新分配）
    *           - deque 头文件<deque>
    *               双向队列。元素在内存中连续存放。随机存取任何元素都能在常数时间完成(仅次于vector)
    *               在两端增删元素具有较佳的性能。
    *               |  |  | a0(head) | a1 | a2 | a3 | (tail) |  |
    *           - list 头文件<list>
    *               双向链表。元素在内存中不连续存放。在任何位置增删元素都能在常数时间完成。
    *               不支持随机存取。
    *           + 顺序容器常用成员函数
    *               - front 返回容器中第一个元素的引用
    *               - back 返回容器中最后一个元素的引用
    *               - push_back 在容器末尾增加新的元素
    *               - pop_back 删除容器末尾的元素
    *               - erase 删除迭代器指向的元素(可能使该迭代器失效)，或删除一个区间，返回被删除元素
    *                   后面的那个元素的迭代器
    *
    *       2. 关联容器 set，multiset，map，multimap
    *           * 元素是排序的
    *           * 插入任何元素，都按照相应的排序规则来确定其位置
    *           * 在查找时具有非常好的性能
    *           * 通常以平衡二叉树方式实现，插入和检索的时间都是O(log(N))
    *           - set/multiset 头文件<set>
    *               set即集合。set中不允许存在相同的元素，multiset允许相同元素存在
    *           - map/multimap 头文件<map>
    *               map与set的不同在于map中存放的元素有且仅有两个成员变量，一个名字为first，另一个名字
    *               为second，map根据first值对元素进行从小到大排序，并可以快速地根据first来检索元素，
    *               map与multimap的不同在于是否允许存在相同first值的元素。
    *
    *       + 顺序容器和关联容器中都有的成员函数
    *           - begin 返回 指向容器中的第一个元素的 迭代器
    *           - end 返回 指向容器中最后一个元素后面的位置的 迭代器
    *           - rbegin 返回 指向容器中最后一个元素的 迭代器
    *           - rend 返回 指向容器中第一个元素前面的位置的 迭代器
    *           - erase 从容器中删除一个或几个元素
    *           - clear 从容器中删除所有元素
    *
    *       3. 容器适配器 stack，queue，priority_queue
    *           - stack 头文件<stack>
    *               栈。是项的有限序列，并满足序列中被删除、检索和修改的项只能是最近插入序列的项(栈顶的顶)
    *               后进先出。
    *           - queue 头文件<queue>
    *               队列。插入只可以在尾部进行，删除、检索和修改只允许从头部进行。
    *               先进先出。
    *           - priority_queue 头文件<queue>
    *               优先级队列。优先级最高的元素总是第一个出列。
    *       对象被插入到容器中的时候，被插入的是对象的一个复制品。许多算法比如排序，查找要求
    *       对容器中的元素进行比较，有的容器本身就是排序的，所以，放入到容器的对象所属的类往
    *       往应该重载 == 和 < 运算符。
    *
    *       + 不同容器上的迭代器差别
    *           - vector        随机访问迭代器
    *           - deque         随机访问迭代器
    *           - list          双向迭代器
    *           - set/multiset  双向迭代器
    *           - map/multimap  双向迭代器
    *           - stack         不支持迭代器
    *           - queue         不支持迭代器
    *           - priority_queue 不支持迭代器
    *           有的算法需要随机访问迭代器的支持，比如sort、binary_search
    *   - 迭代器：可以依次存取容器中的元素，类似指针
    *       - 用于指向顺序容器和关联容器中的元素
    *       - 迭代器用法和指针类似
    *       - 有const和非const两种
    *       - 通过迭代器可以读取它指向的元素
    *       - 通过非const迭代器还能修改其指向的元素
    *       * 定义一个容器类的迭代器的方法可以是
    *           容器类名::iterator 变量名; 或者 容器类名::const_iterator 变量名;
    *       * 访问一个迭代器指向的元素: *迭代器变量名
    *       * 迭代器上可以执行++操作，使其指向容器中下一个元素。如果迭代器到达了容器中的最后一个元素的后面，
    *           此时再使用它，就会出错，类似于使用NULL或者未初始化的指针一样。
    *   - 双向迭代器
    *       若p和p1都是双向迭代器，则可以对p、p1进行以下操作
    *       ++p, p++    使p指向容器中下一个元素
    *       --p, p--    使p指向容器中上一个元素
    *       *p          取p指向的的元素
    *       p = p1      赋值
    *       p == p1     判断是否相等
    *       p != p1     判断是否不等
    *   - 随机访问迭代器
    *       若p和p1都是随机访问迭代器，则可以对p、p1进行以下操作
    *       双向迭代器的所有操作
    *       p += i  将p向后移动i个元素
    *       p -= i  将p向前移动i个元素
    *       p + i   值为：指向p后面的第i个元素的迭代器
    *       p - i   值为：指向p前面的第i个元素的迭代器
    *       p[i]    p后面的第i个元素的引用
    *       p < p1, p <= p1, p > p1, p >= p1
    *   - 算法：用来操作容器中的元素的函数模板
    *       - 比如sort()用来对一个vector中的是数据进行排序
    *       - find()用来搜索一个list中的对象
    *       算法本身与他们操作的数据的类型无关，
    *       因此他们可以在 从 简单数组 到 高度复杂容器 的任意数据结构上 使用
    *           int array[100];该数组就是一个容器，而int*类型的指针变量就可以作为迭代器
    *           sort(array, array+70);sort算法可以作用在该容器上，此例将前70个元素排序
    *
 */
#include <vector>
#include <list>
#include <iostream>
using namespace std;

int main()
{
    vector<int> v;//存放int的数组，一开始没有元素
    v.push_back(1);//添加元素
    v.push_back(2);//添加元素
    v.push_back(3);//添加元素
    v.push_back(4);//添加元素
    vector<int>::const_iterator i;//常量迭代器
    for (i = v.begin(); i != v.end(); ++i)//++操作会使其指向后一个元素
        cout << *i << ",";
    cout << endl;
    vector<int>::reverse_iterator r;//反向迭代器
    for (r = v.rbegin(); r != v.rend(); ++r)//++操作会使其指向前一个元素
        cout << *r << ",";
    cout << endl;
    vector<int>::iterator j;//非常量迭代器
    for (j = v.begin(); j != v.end(); ++j)
        *j = 100;//通过非常量迭代器修改容器内元素值
    for (i = v.begin(); i != v.end(); ++i)
        cout << *i << ",";
    cout << endl;
    //随机访问迭代器测试
    vector<int> mmp(4);
    for (int index = 0; index < mmp.size(); ++index)
        cout << mmp[index];//重载, 根据下标随机访问
    cout << endl;
    vector<int>::const_iterator ii;
    for (ii = mmp.begin(); ii < /*随机访问迭代器可以用<比较位置前后*/mmp.end(); ++ii)
        cout << *ii;
    cout << endl;
    for (ii = mmp.begin(); ii != mmp.end(); ++ii)
        cout << *ii;
    cout << endl;
    ii = mmp.begin();
    while(ii<mmp.end())
    {
        cout << *ii;//间隔输出
        ii += 2;//随机访问迭代器可以直接将p向后移动i个元素
    }
    cout << endl;
    //双向迭代器测试
    //正确的遍历list的方法
    list<int> v2;
    list<int>::const_iterator itr2;
    for ( itr2 = v2.begin();
        itr2 != v2.end();//要用!=比较，用<会报错，双向迭代器不支持<
        ++itr2)
        cout << *itr2;//不能用v2[i]这种，双向迭代器没有operator[]成员函数，要用只能自己写
    cout << endl;
    return 0;
}