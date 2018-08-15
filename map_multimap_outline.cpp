/*
 * template<class Key, class T, class Pred = less<Key>,class A = allocator<T>>
 * class multimap{
 *      ...
 *      typedef pair<const Key, T> value_type;
 *      ...
 *  };
 * //key代表关键字的类型
 *
    * multimap中的元素由关键字，值组成，每一个元素是一个pair对象，关键字就是first成员变量，类型是Key
    * multimap中允许多个元素的关键词相同。元素按照first成员变量从小到大排列，缺省情况下用less<Key>
    *   定义关键字的‘小于’关系
    *
    * 关联容器特别适用于不断更新数据，以及在数据中查询的查询的情况，插入和查询时间复杂度都是O(logN)
    *
    * map中的元素都是pair类模板对象。关键字(first)各不相同。元素按关键字从小到大排列，缺省less<Key>
    *   即 "<" 定义 "小于"
    * map的成员函数[]
    *   若pairs为map模板类的对象，
    *   pairs[key]
    *   返回关键字等于key的元素的值(second)的引用。若没有关键字为key的元素，则会往pairs里面插入
    *   一个关键字为key的元素，其值用无参构造函数初始化，并返回其值的引用。
    *       如：
    *       map<int,double> pairs;
    *       则
    *       paris[50]=5;会修改pairs中关键字为50的元素，使其值变成5.
    *       若不存在关键字为50的元素，则插入该元素，并使其值变成5。
*/
//#define example_1
//#define example_2
#define example_3

#ifdef example_1
#include <iostream>
#include <map>
using namespace std;
int main()
{
    typedef multimap<int, double, less<int> > mmid;
    mmid pairs;
    cout << "1)" << pairs.count(15) << endl;
    pairs.insert(mmid::value_type(15, 2.7));//typedef pair<const Key, T> value_type;
    pairs.insert(mmid::value_type(15, 99.3));
    cout << "2)" << pairs.count(15) << endl;//求关键字等于某值的元素个数
    pairs.insert(mmid::value_type(30, 111.11));
    pairs.insert(mmid::value_type(10, 22.22));
    pairs.insert(mmid::value_type(25, 33.333));
    pairs.insert(mmid::value_type(20, 9.3));
    for (mmid::const_iterator i = pairs.begin(); i != pairs.end(); ++i)
        cout << "(" << i->first << "," << i->second << ")" << ",";
        //输出(10,22.22),(15,2.7),(15,99.3),(20,9.3),(25,33.333),(30,111.11),

    return 0;
}
#endif

#ifdef example_2
#include <iostream>
#include <map>
#include <string>
using namespace std;
class CStudent
{
public:
    struct CInfo // 类的内部还可以定义类
    {
        int id;//学号
        string name;
    };
    int score;//Key
    CInfo info;
};

typedef multimap<int, CStudent::CInfo> MAP_STD;

int main(int argc, char *argv[])
{
    MAP_STD mp;
    CStudent st;
    string cmd;
    while (cin >> cmd) {
        if (cmd == "Add" or cmd == "add") {
            cin >> st.info.name >> st.info.id >> st.score;
            mp.insert(MAP_STD::value_type(st.score, st.info));
//            mp.insert(make_pair(st.score, st.info));//和上面等效
        }
        else if (cmd == "Query" or cmd == "query") {
            int score;
            cin >> score;
            MAP_STD::iterator p = mp.lower_bound(score);
            if (p != mp.begin()) {
                --p;//lowerbound返回[begin(),it)迭代器
                score = p->first;//比查询分数要低的最高分
                MAP_STD::iterator max_p = p;
                int max_id = p->second.id;//记录当前最大成绩对应的学号
                for (; p != mp.begin() && p->first == score; --p) {
                    if (p->second.id > max_id) {
                        max_p = p;
                        max_id = p->second.id;
                    }
                }
                if (p->first == score) {
                    //如果for循环是因为p==begin()而停止，则p所指向的元素还要处理
                    if (p->second.id > max_id) {
                        max_p = p;
                        max_id = p->second.id;
                    }
                }
                cout << max_p->second.name
                     << " "
                     << max_p->second.id
                     << " "
                     << max_p->first << endl;
            }
            else
                cout << "Nobody" << endl;
        }
    }
    return 0;
}
#endif

#ifdef example_3
#include <iostream>
#include <map>
using namespace std;
template <class Key, class Value>
ostream& operator<< (ostream& o, const pair<Key, Value>& p)
{
    o << "(" << p.first << "," << p.second << ")";
    return o;
}
int main(int argc, char* argv[])
{
    typedef map<int, double> mmid;
    mmid pairs;
    cout << "1)" << pairs.count(15) << endl;
    pairs.insert(make_pair(15, 2.7));
    pairs.insert(make_pair(15, 99.3));//本次插入会失败
    cout << "2)" << pairs.count(15) << endl;
    pairs.insert(make_pair(20, 9.3));
    mmid::iterator i;
    cout << "3)";
    for (i=pairs.begin(); i != pairs.end();++i)
        cout << *i << ",";
    cout << endl;
    cout << "4)";
    int n = pairs[40];//如果没有关键字为40的元素，则新建并插入
    for(i = pairs.begin(); i != pairs.end(); ++i)
        cout << *i << ",";
    cout << endl;
    cout << "5)";
    pairs[15] = 6.28;//把关键字为15的元素值给成6.28
    for(i = pairs.begin(); i != pairs.end(); ++i)
        cout << *i << ",";
    return 0;
}
#endif