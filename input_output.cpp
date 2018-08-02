/*
 * ios是最开始的基类
 * ios派生出istream 和 ostream
 * istream又派生出ifstream，ostream又派生出ofstream
 * istream和ostream一起派生出iostream，iostream又派生出fstream
 * 各个类的用途：
 *  - istream 用于输入的流类，cin就是该类的对象
 *  - ostream 用于输出的流类，cout就是该类对象
 *  - ifstream 用于从文件中读取数据的类
 *  - ofstream 用于向文件中写入数据的类
 *  - iostream 既能用于输出，也能用于输入的类
 *  - fstream 既能从文件中读取数据，又能向文件中写入数据的类
 * 标准流对象
 *  - cin 与标准输入设备相连
 *      对应于标准输入流，用于从键盘读取数据，也可以重定向为从文件中读取数据
 *  - cout 与标准输出设备相连
 *      对应于标准输出流，用于向屏幕输出数据也可以重定向为向文件写入数据数据
 *  - cerr 与标准错误输出设备相连
 *      用于向屏幕输出错误信息
 *  - clog 与标准错误输出设备相连
 *  用于向屏幕输出错误信息
 *  缺省情况下
 *      cerr<<"str"<<endl;
 *      clog<<"str"<<endl;
 *      cout<<"str"<<endl;
 *      //这三个语句等价
 *  cerr和clog的区别在于cerr不使用缓冲区，直接向显示器输出信息；
 *  而输出到clog的信息会先被存放到缓冲区，缓冲区满或者刷新时才会输出到屏幕
 * 判断流结束
 *  int x;
 *  while(cin>>x){...}//
 *  因为istream& operator>>(int a){...return *this};return istreram的引用，while循环条件是一个强制类型转换重载
 *  - 从文件输入，读到文件尾，也算结束
 *  - 从键盘输入，则在单独一行输入CTRL+Z代表输入流结束
 * */
/*
 * istream类的成员函数
 *  - istream& getline(char* buf, int bufSize);
 *      从输入流读取bufSize-1个字符到缓冲区buf，或者碰到‘\n’为止(哪个先到算哪个)
 *  - istream& getline(char* buf, int bufSize, char delim);//分隔符delim
 *      从输入流读取bufSize-1个字符到缓冲区buf，或者碰到delim字符为止(哪个先到算哪个)
 *  - 两个函数都会自动在buf中读入的数据结尾添加‘\0’。‘\n’或delim都不会被读入入buf，但会被函数从输入流中取走
 *      如果输入流中‘\n’或delim之前的字符个数 达到或超过了 bufSize个，就会导致读入出错，结果就是：
 *      本次读取虽已完成，但下次读取都会失败
 *  - 使用if(!cin.getline(...))判断输入是否结束
 *  - bool eof();判断输入流是否结束
 *  - int peek();返回下一个字符，但不会从流中去掉
 *  - istream& putback(char c);将字符ch放回输入流
 *  - istream& ignore(int nCount = 1, int delim = EOF);从流中删掉最多nCount个字符，遇到EOF时结束
 * 流操纵算子自学
 */
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
    int x,y;
    cin >> x >> y;
    //将标准输出重定向到test.txt文件
    freopen("test1.txt", "w", stdout);//不起作用，原因未知，猜测是平台问题win10 minGW64
    //已经找到原因，起作用了，是在cmake-build-debug文件夹里面，没看到而已
    if(y==0)//除数为零错误
        cerr<<"error."<<endl, clog << "clog"<<endl;
    else
        cout << x/y<< endl;
    fclose(stdout);
    //试一下输入重定向
    int f; int n;
    //不起作用，原因未知，猜测是平台问题win10 minGW64
    freopen("test2.txt", "r", stdin);//重定向cin成为从文件中读取数据
    cin >> f >> n;
    fclose(stdin);
    clog << f << "," << n << endl;//正常输出
    cout << f << "," << n << endl;//之前已经fclose了，但是不能输出到屏幕，也没有输出到test1.txt中
    //看来fclose()之后，并不能呢个恢复到之前的定向
    //这里试一下再次重定向到控制台
    freopen("CON", "w", stdout);
    freopen("CON", "r", stdin);
    cout << "cout back";//并不管用
    cout << f << "," << n << endl;
    return 0;
}