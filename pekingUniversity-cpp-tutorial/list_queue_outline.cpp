//deque读作dek，不读作DQ
//deque读作dek，不读作DQ
//deque读作dek，不读作DQ

/*
    * list容器
    *   - 双向链表 #include <list>
    *   - 在任何位置插入删除都是常数时间
    *   - 不支持根据下标随机存取元素
    *   - 具有所有顺序容器都有的成员函数
    *   - 还支持8个成员函数
    *       - push_front    在链表最前端插入
    *       - pop_front     删除链表最前端元素
    *       - sort          排序(list不支持STL的算法sort)
    *       - remove        删除和指定值相等的所有元素
    *       - unique        删除和前一个元素相同的元素
    *       - merge         合并两个链表，并清空被合并的链表
    *       - reverse       颠倒链表
    *       - splice        在指定位置前面插入另一链表中的一个或者多个元素，并在另一链表中删除被插入元素
    * list容器之sort()函数
    *   - list容器的迭代器不支持完全随机访问->不能用标准库中sort函数对list进行排顺序
    *   - 但是list有自己的排序成员函数sort()
    *       list<T> classname;
    *       classname.sort(compare);//compare函数自己定义
    *       classname.sort();//无参数，按照<排序
    *   - list只能使用双向迭代器->不支持大于/小于比较运算符,[]运算符和随机移动( 迭代器+i 这种移动)
*/
/*
    * deque容器
    *   - 双向队列
    *   - 包含头文件<deque>
    *   - 所有适用于vector的操作都适用于deque
    *   - deque还有push_front(将元素插入到容器头部)和pop_front操作
    *
*/
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;
class A
{
private:
    int n;
public:
    A(int n_)
        : n(n_)
    {}
    friend bool operator<(const A &a1, const A &a2);
    friend bool operator==(const A &a1, const A &a2);
    friend ostream &operator<<(ostream &o, const A &a);

};
bool operator<(const A &a1, const A &a2)
{
    return a1.n < a2.n;
}
bool operator==(const A &a1, const A &a2)
{
    return a1.n == a2.n;
}
ostream &operator<<(ostream &o, const A &a)
{
    o << a.n;
    return o;
}
template<class T>
void PrintList(const list<T> &lst)
{
    int tmp = lst.size();
    if (tmp > 0) {
        //typename用来说明list<T>::const_iterator是个类型，在VS中可以不写
        typename list<T>::const_iterator i;
        i = lst.begin();
        for (i = lst.begin(); i != lst.end(); ++i)
            cout << *i << ",";

    }
}
int main(int argc, char *argv[])
{
    list<A> lst1, lst2;
    lst1.push_back(1);lst1.push_back(3);lst1.push_back(2);lst1.push_back(4);
    lst1.push_back(2);lst2.push_back(10);lst2.push_front(20);lst2.push_back(30);
    lst2.push_back(30);lst2.push_back(30);lst2.push_front(40);lst2.push_back(40);
    cout << "1) ";PrintList(lst1);cout << endl;
    cout << "2) ";PrintList(lst2);cout << endl;
    lst2.sort();
    cout << "3) ";PrintList(lst2);cout << endl;
    lst2.pop_front();//删掉10
    cout << "4)";PrintList(lst2);cout << endl;
    lst1.remove(2);//删除所有和A(2)相等的元素
    cout << "5)";PrintList(lst1);cout << endl;
    lst2.unique();//所有相同值的元素只留一个
    cout << "6)";PrintList(lst2);cout << endl;
    lst1.merge(lst2);//合并lst2到lst1，并且清空lst2
    cout << "7)";PrintList(lst1);cout << endl;
    cout << "8)";PrintList(lst2);cout << endl;
    lst1.reverse();
    cout << "9)";PrintList(lst1);cout << endl;
    lst2.push_back(100);lst2.push_back(200);
    lst2.push_back(300);lst2.push_back(400);
    cout << "10)";PrintList(lst2);cout << endl;
    list<A>::iterator p1, p2, p3;
    p1 = find(lst1.begin(), lst1.end(), 3);
    p2 = find(lst2.begin(), lst2.end(), 200);
    p3 = find(lst2.begin(), lst2.end(), 400);
    lst1.splice(p1, lst2, p2, p3);//将[p2,p3)插入到p1之前，并从lst2中删除[p2,p3)
    cout << "11)";PrintList(lst1);cout << endl;
    cout << "12)";PrintList(lst2);cout << endl;
    return 0;
}