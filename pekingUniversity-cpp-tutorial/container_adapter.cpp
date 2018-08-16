/*
    * 容器适配器-可以用某种顺序容器来实现（让已有的顺序容器以队列或栈的方式工作）
    *   1) stack：头文件<stack>
    *       - 栈 -- 后进先出
    *       - 只能插入删除访问栈顶的元素
    *       - 可以用vector、list、deque来实现
    *           - 缺省使用deque实现
    *           - 用vector和deque实现，比用list性能好
    *
    *           template<class T, class Cont = deque<T> >
    *           class stack{...};
    *
    *       - stack中主要的三个成员函数
    *           - void push(const T& x);    将x压入栈顶
    *           - void pop();               弹出栈顶元素
    *           - T& top();                 返回栈顶元素的引用，通过该函数，可以读取栈顶元素的值
    *                                       也可以修改栈顶元素
    *
    *   2) queue：头文件<queue>
    *       - 队列 -- 先进先出
    *       - 和stack基本类似，可以使用list和deque实现
    *       - 缺省使用deque实现
    *           template <class T, class Cont = deque<T> >
    *           class queue{...};
    *       - 同样有push、pop、top函数
    *           - push作用在队尾
    *           - pop、top作用在队头，先进先出
    *
    *   3) priority_queue：头文件<queue>
    *       - 优先级队列 -- 最高优先级元素总是第一个出列
    *       - 和queue类似，可以使用vector和deque实现
    *       - 缺省情况下使用vector实现
    *       - priority_queue 通常使用堆排序技术实现，保证最大的元素总是在最前面
    *           - 执行pop操作时，删除的是最大元素
    *           - 执行top操作时，返回的是最大元素的引用
    *       - 默认元素比较器是less<T>
    *
    * *都有三个成员函数
    *   - push  添加一个元素
    *   - top   返回栈顶或队头元素的引用
    *   - pop   删除一个元素
    * *容器适配器上没有迭代器->STL中各种排序查找变序算法都不适合容器适配器
    *
*/
#define priority_queue_eg_1
#ifdef priority_queue_eg_1
#include <iostream>
#include <queue>
using namespace std;
int main(int argc, char* argv[])
{
    priority_queue<double> priorities;
    priorities.push(3.2);
    priorities.push(9.8);
    priorities.push(5.4);
    while(!priorities.empty())
    {
        cout  << priorities.top() << " ";
        priorities.pop();
    }
    return 0;
}
#endif